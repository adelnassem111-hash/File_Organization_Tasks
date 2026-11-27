
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of persons must be greater than 0." << endl;
        return 1;
    }

    ofstream saveFile("persons.txt");
    if (!saveFile) {
        cerr << "Error creating persons.txt!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Enter person " << (i + 1) << " name (single word, e.g. Ali): ";
        cin >> name;
        cout << "Enter person " << (i + 1) << " age: ";
        cin >> age;

        saveFile << name << " " << age << endl;
    }
    saveFile.close();

    ifstream loadFile("persons.txt");
    if (!loadFile) {
        cerr << "Error opening persons.txt!" << endl;
        return 1;
    }

    vector<Person> persons;
    Person temp;
    while (loadFile >> temp.name >> temp.age) {
        persons.push_back(temp);
    }
    loadFile.close();

    if (persons.empty()) {
        cerr << "No valid person data found in file!" << endl;
        return 1;
    }

    Person youngest = persons[0];
    Person oldest = persons[0];

    for (size_t i = 1; i < persons.size(); i++) {
        if (persons[i].age < youngest.age) {
            youngest = persons[i];
        }
        if (persons[i].age > oldest.age) {
            oldest = persons[i];
        }
    }

    ofstream resFile("results.txt");
    if (!resFile) {
        cerr << "Error creating results.txt!" << endl;
        return 1;
    }

    resFile << "Younger Person: " << youngest.name << " (" << youngest.age << ")" << endl;
    resFile << "Older Person: " << oldest.name << " (" << oldest.age << ")" << endl;
    resFile.close();

    cout << "Saved younger and older persons to results.txt" << endl;

    return 0;
}
