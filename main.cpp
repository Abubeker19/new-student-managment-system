#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;
const int NAME_LENGTH = 50;

class StudentManager {
private:
    char names[MAX_STUDENTS][NAME_LENGTH];
    int ids[MAX_STUDENTS];
    int ages[MAX_STUDENTS];
    int totalStudents;

public:
    StudentManager() {
        totalStudents = 0;
    }

    void addStudent() {
        if (totalStudents >= MAX_STUDENTS) {
            cout << "Cannot add more students.\n";
            return;
        }

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(names[totalStudents], NAME_LENGTH);
        cout << "Enter ID: ";
        cin >> ids[totalStudents];
        cout << "Enter age: ";
        cin >> ages[totalStudents];

        totalStudents++;
        cout << "Student added successfully.\n";
    }

    void displayStudents() {
        if (totalStudents == 0) {
            cout << "No students to display.\n";
            return;
        }

        for (int i = 0; i < totalStudents; i++) {
            cout << "Name: " << names[i]
                 << ", ID: " << ids[i]
                 << ", Age: " << ages[i] << "\n";
        }
    }

    void searchStudent() {
        if (totalStudents == 0) {
            cout << "No students to search.\n";
            return;
        }

        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (int i = 0; i < totalStudents; i++) {
            if (ids[i] == id) {
                cout << "Student found: Name = " << names[i]
                     << ", Age = " << ages[i] << "\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void updateStudent() {
        if (totalStudents == 0) {
            cout << "No students to update.\n";
            return;
        }

        int id;
        cout << "Enter ID to update: ";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < totalStudents; i++) {
            if (ids[i] == id) {
                cout << "Enter new name: ";
                cin.getline(names[i], NAME_LENGTH);
                cout << "Enter new age: ";
                cin >> ages[i];
                cout << "Student updated successfully.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void deleteStudent() {
        if (totalStudents == 0) {
            cout << "No students to delete.\n";
            return;
        }

        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for (int i = 0; i < totalStudents; i++) {
            if (ids[i] == id) {
                for (int j = i; j < totalStudents - 1; j++) {
                    strcpy(names[j], names[j + 1]);
                    ids[j] = ids[j + 1];
                    ages[j] = ages[j + 1];
                }
                totalStudents--;
                cout << "Student deleted successfully.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }
};

int main() {
    StudentManager sm;
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sm.addStudent();
                break;
            case 2:
                sm.displayStudents();
                break;
            case 3:
                sm.searchStudent();
                break;
            case 4:
                sm.updateStudent();
                break;
            case 5:
                sm.deleteStudent();
                break;
            case 6:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
