#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("fruit.txt");
    if (!inFile) {
        cerr << "Error opening fruit.txt for reading!" << endl;
        return 1;
    }

    string line;
    cout << "--- Contents of fruit.txt ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening fruit.txt for appending!" << endl;
        return 1;
    }

    outFile << "Fresh Fruits" << endl;
    outFile.close();

    cout << "\nAppended 'Fresh Fruits' to fruit.txt successfully." << endl;

    return 0;
}
