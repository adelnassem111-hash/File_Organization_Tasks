#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fullName;
    int id;
    float grade;

    cout << "Enter Full Name: ";
    getline(cin, fullName);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Grade: ";
    cin >> grade;

    ofstream outFile("Student.txt");
    if (!outFile) {
        cerr << "Error creating Student.txt!" << endl;
        return 1;
    }

    outFile << "Full Name: " << fullName << endl;
    outFile << "ID: " << id << endl;
    outFile << "Grade: " << grade << endl;

    outFile.close();
    cout << "Data saved successfully to Student.txt" << endl;

    return 0;
}
