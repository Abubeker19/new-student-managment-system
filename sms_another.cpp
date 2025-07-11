#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;
const int NAME_LENGTH = 50;

char names[MAX_STUDENTS][NAME_LENGTH];
int ids[MAX_STUDENTS];
int ages[MAX_STUDENTS];
int totalStudents = 0;

// Save current student data to file "students.txt"
void saveToFile() {
    ofstream file("students.txt");
    for (int i = 0; i < totalStudents; i++) {
        file << ids[i] << "," << names[i] << "," << ages[i] << "\n";
    }
    file.close();
}

// Load student data from file "students.txt"
void loadFromFile() {
    ifstream file("students.txt");
    if (!file.is_open()) return; // If file doesn't exist, skip loading

    totalStudents = 0;
    char line[100];
    while (file.getline(line, 100)) {
        char* token = strtok(line, ",");
        if (token) ids[totalStudents] = atoi(token);

        token = strtok(NULL, ",");
        if (token) strcpy(names[totalStudents], token);

        token = strtok(NULL, ",");
        if (token) ages[totalStudents] = atoi(token);

        totalStudents++;
    }

    file.close();
}

void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        cout << "Cannot add more students.\n";
        return;
    }

    cout << "Enter student name: ";
    cin.ignore();
    cin.getline(names[totalStudents], NAME_LENGTH);
    cout << "Enter student ID: ";
    cin >> ids[totalStudents];
    cout << "Enter student age: ";
    cin >> ages[totalStudents];

    totalStudents++;
    saveToFile(); // Save after adding
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (totalStudents == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nList of Students:\n";
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
    cout << "Enter student ID to search: ";
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
    cout << "Enter student ID to update: ";
    cin >> id;
    cin.ignore(); // Clear newline from input buffer

    for (int i = 0; i < totalStudents; i++) {
        if (ids[i] == id) {
            cout << "Enter new name: ";
            cin.getline(names[i], NAME_LENGTH);
            cout << "Enter new age: ";
            cin >> ages[i];
            saveToFile(); // Save after update
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
    cout << "Enter student ID to delete: ";
    cin >> id;

    for (int i = 0; i < totalStudents; i++) {
        if (ids[i] == id) {
            // Shift all students after i to the left to overwrite deleted student
            for (int j = i; j < totalStudents - 1; j++) {
                strcpy(names[j], names[j + 1]);
                ids[j] = ids[j + 1];
                ages[j] = ages[j + 1];
            }
            totalStudents--;
            saveToFile(); // Save after delete
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

int main() {
    loadFromFile(); // Load data on program start

    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student by ID\n";
        cout << "5. Delete Student by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);

    return 0;
}
