#include <iostream>
#include <map>
using namespace std;

// Function to add students
void addStudent(map<string, float>& students) {
    string name;
    float grade;

    cout << "Enter student name: ";
    cin >> name;

    cout << "Enter grade: ";
    cin >> grade;

    students[name] = grade;

    cout << "Student added successfully!\n";
}

// Function to retrieve grade
void retrieveGrade(map<string, float>& students) {
    string name;

    cout << "Enter student name to search: ";
    cin >> name;

    if (students.find(name) != students.end()) {
        cout << "Grade of " << name
             << " is " << students[name] << endl;
    }
    else {
        cout << "Student not found!\n";
    }
}

// Function to update grade
void updateGrade(map<string, float>& students) {
    string name;
    float newGrade;

    cout << "Enter student name to update: ";
    cin >> name;

    if (students.find(name) != students.end()) {

        cout << "Enter new grade: ";
        cin >> newGrade;

        students[name] = newGrade;

        cout << "Grade updated successfully!\n";
    }
    else {
        cout << "Student not found!\n";
    }
}

// Function to delete student
void deleteStudent(map<string, float>& students) {
    string name;

    cout << "Enter student name to delete: ";
    cin >> name;

    if (students.find(name) != students.end()) {

        students.erase(name);

        cout << "Student deleted successfully!\n";
    }
    else {
        cout << "Student not found!\n";
    }
}

// Function to display all students
void displayStudents(map<string, float>& students) {

    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    for (auto it = students.begin();
         it != students.end(); it++) {

        cout << "Name: " << it->first
             << " | Grade: " << it->second << endl;
    }
}

int main() {

    map<string, float> students;

    int choice;

    do {
        cout << "\n===== Student Grade System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Retrieve Grade\n";
        cout << "3. Update Grade\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            addStudent(students);
            break;

        case 2:
            retrieveGrade(students);
            break;

        case 3:
            updateGrade(students);
            break;

        case 4:
            deleteStudent(students);
            break;

        case 5:
            displayStudents(students);
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}