#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/**
 * Student struct representing a student with name, ID number, and homework scores
 */
struct Student {
    std::string name;
    int studentNumber;
    double* homeworkScores;  // Dynamically allocated array
    int numHomeworks;
    
    // Constructor
    Student(const std::string& studentName, int number, int numAssignments);
    
    // Destructor to free dynamically allocated memory
    ~Student();
    
    // Copy constructor
    Student(const Student& other);
    
    // Assignment operator
    Student& operator=(const Student& other);
    
    // Calculate average homework score
    double getAverageScore() const;
    
    // Print student information
    void print() const;
};

/**
 * Node struct for linked list
 */
struct StudentNode {
    Student* student;
    StudentNode* next;
    
    // Constructor
    StudentNode(Student* s);
    
    // Destructor
    ~StudentNode();
};

/**
 * Linked list functions
 */

// Add a student to the front of the list
void addStudent(StudentNode*& head, Student* student);

// Add a student to the end of the list
void addStudentToEnd(StudentNode*& head, Student* student);

// Print all students in the list
void printAllStudents(StudentNode* head);

// Delete the entire list and free memory
void deleteList(StudentNode*& head);

// Get the number of students in the list
int getListSize(StudentNode* head);

// Find a student by student number
Student* findStudent(StudentNode* head, int studentNumber);

#endif // STUDENT_H
