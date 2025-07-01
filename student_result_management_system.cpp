#include <iostream>
#include <iomanip>   // For setw, setprecision
#include <string>    // For getline
#include <vector>    // For dynamic array (vector)

using namespace std;

// Structure to store student data
struct Student {
    string name;
    string rollNo;
    float eng, math, sci;
    float total;
    float percentage;
    string grade;
};

// Function to calculate grade
string calculateGrade(float percentage) {
    if (percentage >= 80) return "A";
    else if (percentage >= 70) return "B";
    else if (percentage >= 60) return "C";
    else if (percentage >= 50) return "D";
    else return "Fail";
}

// Function to calculate total and grade
void computeResult(Student &s) {
    s.total = s.eng + s.math + s.sci;
    s.percentage = s.total / 3.0;
    s.grade = calculateGrade(s.percentage);
}

// Add a new student
void addStudent(vector<Student> &students) {
    Student s;
    cin.ignore(); // clear buffer
    cout << "\nEnter Name: ";
    getline(cin, s.name);
    cout << "Enter Roll No: ";
    getline(cin, s.rollNo);
    cout << "Enter Marks (English, Math, Science): ";
    cin >> s.eng >> s.math >> s.sci;

    computeResult(s);
    students.push_back(s);
    cout << "? Student added successfully!\n";
}

// Display all students
void displayAll(const vector<Student> &students) {
    if (students.empty()) {
        cout << "?? No student records found.\n";
        return;
    }

    cout << "\n--- All Student Results ---\n";
    cout << "-----------------------------------------------------------\n";
    cout << left << setw(12) << "Name"
         << setw(10) << "Roll No"
         << setw(8) << "Total"
         << setw(8) << "%"
         << setw(10) << "Grade" << endl;
    cout << "-----------------------------------------------------------\n";

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        cout << left << setw(12) << s.name
             << setw(10) << s.rollNo
             << setw(8) << s.total
             << setw(8) << fixed << setprecision(1) << s.percentage
             << setw(10) << s.grade << endl;
    }
}

// Search a student by roll number
void searchStudent(const vector<Student> &students) {
    cin.ignore();
    string roll;
    cout << "Enter Roll No to search: ";
    getline(cin, roll);

    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        if (s.rollNo == roll) {
            cout << "\n?? Student Found:\n";
            cout << "Name: " << s.name << endl;
            cout << "Marks - English: " << s.eng
                 << ", Math: " << s.math
                 << ", Science: " << s.sci << endl;
            cout << "Total: " << s.total
                 << ", %: " << s.percentage
                 << ", Grade: " << s.grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "? Student not found!\n";
    }
}

// Update student marks
void updateStudent(vector<Student> &students) {
    cin.ignore();
    string roll;
    cout << "Enter Roll No to update: ";
    getline(cin, roll);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            cout << "Enter new marks (English, Math, Science): ";
            cin >> students[i].eng >> students[i].math >> students[i].sci;
            computeResult(students[i]);
            cout << "? Marks updated.\n";
            return;
        }
    }
    cout << "? Student not found!\n";
}

// Delete a student record
void deleteStudent(vector<Student> &students) {
    cin.ignore();
    string roll;
    cout << "Enter Roll No to delete: ";
    getline(cin, roll);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            students.erase(students.begin() + i);
            cout << "??? Student deleted.\n";
            return;
        }
    }
    cout << "? Student not found!\n";
}

// Main menu
int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n====== Student Result Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayAll(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: deleteStudent(students); break;
            case 6: cout << "?? Exiting system...\n"; break;
            default: cout << "?? Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

