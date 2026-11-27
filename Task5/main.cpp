#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim;
};

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening students.txt!" << endl;
        return 1;
    }

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        Student s;
        s.delim = '$';

        cout << "Enter Student Name (max 19 chars): ";
        cin.getline(s.name, 20);
        if (strlen(s.name) == 0) {
            cin.getline(s.name, 20);
        }

        cout << "Enter Student ID: ";
        while (!(cin >> s.id)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid ID. Enter integer ID: ";
        }

        cout << "Enter Student Grade: ";
        while (!(cin >> s.grade)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Grade. Enter numeric Grade: ";
        }

        outFile << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Add another student? (y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');
    }

    outFile.close();
    cout << "Student records saved to students.txt" << endl;

    return 0;
}
