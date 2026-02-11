#include <iostream>
#include <string>
#include <limits>
#include "Student.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    StudentNode* studentList = nullptr;
    int numStudents;
    
    cout << "=== Student Management System ===" << endl;
    cout << "\nHow many students will be entered? ";
    
    while (!(cin >> numStudents) || numStudents < 0) {
        cout << "Invalid input. Please enter a non-negative number: ";
        clearInput();
    }
    clearInput();
    
    if (numStudents == 0) {
        cout << "\nNo students to enter." << endl;
        return 0;
    }
    
    // Enter each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\n--- Student " << (i + 1) << " of " << numStudents << " ---" << endl;
        
        string name;
        int studentNumber;
        int numHomeworks;
        
        cout << "Enter student name: ";
        getline(cin, name);
        
        cout << "Enter student number: ";
        while (!(cin >> studentNumber)) {
            cout << "Invalid input. Please enter a number: ";
            clearInput();
        }
        
        cout << "Enter number of homework assignments: ";
        while (!(cin >> numHomeworks) || numHomeworks < 0) {
            cout << "Invalid input. Please enter a non-negative number: ";
            clearInput();
        }
        clearInput();
        
        // Create student with dynamically allocated homework array
        Student* student = new Student(name, studentNumber, numHomeworks);
        
        // Enter homework scores
        if (numHomeworks > 0) {
            cout << "Enter " << numHomeworks << " homework scores:" << endl;
            for (int j = 0; j < numHomeworks; j++) {
                cout << "  Homework " << (j + 1) << ": ";
                while (!(cin >> student->homeworkScores[j])) {
                    cout << "  Invalid input. Please enter a number: ";
                    clearInput();
                }
            }
            clearInput();
        }
        
        // Add student to linked list
        addStudentToEnd(studentList, student);
        cout << "Student added successfully!" << endl;
    }
    
    // Print all students
    printAllStudents(studentList);
    
    // Clean up memory
    deleteList(studentList);
    
    cout << "\nProgram completed successfully!" << endl;
    
    return 0;
}
