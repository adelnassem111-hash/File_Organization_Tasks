#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // علشان remove و rename

using namespace std;

int main() {
    const string filename = "grades.txt";
    const string tempFilename = "temp_grades.txt";

    // 1. إنشاء الملف وكتابة 5 درجات صحيحة (int)
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not create " << filename << endl;
        return 1;
    }

    int gradesToWrite[5] = {85, 90, 78, 92, 88};
    for (int i = 0; i < 5; i++) {
        outFile << gradesToWrite[i] << endl;
    }
    outFile.close();
    cout << "Step 1: Created " << filename << " and wrote 5 integer grades.\n\n";

    // 2. قراءة وطباعة الدرجات باستخدام loop صحيحة
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open " << filename << " for reading.\n";
        return 1;
    }

    cout << "Step 2: Current grades in " << filename << ":\n";
    int grade;
    // القراءة الصحيحة في C++ بتكون جوه شرط الـ while مباشرة
    while (inFile >> grade) {
        cout << "- " << grade << endl;
    }
    inFile.close();
    cout << endl;

    // 3. سؤال المستخدم عن درجة لحذفها، وإنشاء ملف مؤقت بدونها
    int gradeToDelete;
    cout << "Step 3: Enter a grade to delete: ";
    cin >> gradeToDelete;

    ifstream readForDelete(filename);
    ofstream tempFile(tempFilename);

    if (!readForDelete || !tempFile) {
        cerr << "Error: Failed to open files for deletion process.\n";
        return 1;
    }

    bool found = false;
    while (readForDelete >> grade) {
        if (grade == gradeToDelete && !found) {
            // بنحذف أول تطابق للدرجة المطلوبة (لو عايز تحذف كل التكرارات شيل && !found)
            found = true;
            continue;
        }
        tempFile << grade << endl;
    }

    readForDelete.close();
    tempFile.close();

    // 4. استبدال الملف الأصلي بالملف المؤقت وعرض رسالة نجاح أو خطأ
    if (remove(filename.c_str()) != 0) {
        cerr << "Error: Could not delete the original file " << filename << endl;
        remove(tempFilename.c_str()); // تنظيف الملف المؤقت
        return 1;
    }

    if (rename(tempFilename.c_str(), filename.c_str()) != 0) {
        cerr << "Error: Could not rename temporary file to " << filename << endl;
        return 1;
    }

    if (found) {
        cout << "Success: Grade " << gradeToDelete << " was deleted and " << filename << " was updated.\n";
    } else {
        cout << "Notice: Grade " << gradeToDelete << " was not found. File replaced without removing any grade.\n";
    }

    // طباعة المحتوى النهائي للتأكد في الـ terminal
    ifstream finalRead(filename);
    if (finalRead) {
        cout << "\nUpdated grades in " << filename << ":\n";
        while (finalRead >> grade) {
            cout << "- " << grade << endl;
        }
        finalRead.close();
    }

    return 0;
}
