#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string text = "Hello Everybody";

    ofstream outFile("welcome.txt");
    if (!outFile) {
        cerr << "Error opening welcome.txt!" << endl;
        return 1;
    }
    outFile << text;
    outFile.close();

    ifstream inFile("welcome.txt");
    if (!inFile) {
        cerr << "Error reading welcome.txt!" << endl;
        return 1;
    }
    string fileContent;
    getline(inFile, fileContent);
    inFile.close();

    string target = "body";
    string replacement = "one";
    size_t pos = fileContent.find(target);
    if (pos != string::npos) {
        fileContent.replace(pos, target.length(), replacement);
    }

    ofstream updateFile("welcome.txt");
    if (!updateFile) {
        cerr << "Error updating welcome.txt!" << endl;
        return 1;
    }
    updateFile << fileContent;
    updateFile.close();

    cout << "Final text written to welcome.txt: " << fileContent << endl;

    return 0;
}
