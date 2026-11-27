#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "How many names do you want to enter? ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid positive number: ";
    }
    cin.ignore(1000, '\n');

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter name " << (i + 1) << ": ";
        getline(cin, names[i]);
    }

    sort(names.begin(), names.end());

    ofstream outFile("sorted_names.txt");
    if (!outFile) {
        cerr << "Error creating sorted_names.txt!" << endl;
        return 1;
    }

    cout << "\n--- Sorted Names ---" << endl;
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
        outFile << names[i] << endl;
    }

    outFile.close();
    cout << "\nSorted names saved to sorted_names.txt" << endl;

    return 0;
}
