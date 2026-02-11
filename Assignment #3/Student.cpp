#include "Student.h"
#include <iostream>
#include <iomanip>

// Student implementation

Student::Student(const std::string& studentName, int number, int numAssignments)
    : name(studentName), studentNumber(number), numHomeworks(numAssignments) {
    // Allocate array for homework scores
    homeworkScores = new double[numHomeworks];
    
    // Initialize all scores to 0
    for (int i = 0; i < numHomeworks; i++) {
        homeworkScores[i] = 0.0;
    }
}

Student::~Student() {
    // Free dynamically allocated memory
    delete[] homeworkScores;
}

Student::Student(const Student& other)
    : name(other.name), studentNumber(other.studentNumber), numHomeworks(other.numHomeworks) {
    // Deep copy the homework scores array
    homeworkScores = new double[numHomeworks];
    for (int i = 0; i < numHomeworks; i++) {
        homeworkScores[i] = other.homeworkScores[i];
    }
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        // Free existing memory
        delete[] homeworkScores;
        
        // Copy data
        name = other.name;
        studentNumber = other.studentNumber;
        numHomeworks = other.numHomeworks;
        
        // Deep copy homework scores
        homeworkScores = new double[numHomeworks];
        for (int i = 0; i < numHomeworks; i++) {
            homeworkScores[i] = other.homeworkScores[i];
        }
    }
    return *this;
}

double Student::getAverageScore() const {
    if (numHomeworks == 0) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (int i = 0; i < numHomeworks; i++) {
        sum += homeworkScores[i];
    }
    
    return sum / numHomeworks;
}

void Student::print() const {
    std::cout << "Student #" << studentNumber << ": " << name << std::endl;
    std::cout << "  Homework Scores (" << numHomeworks << " assignments): ";
    
    for (int i = 0; i < numHomeworks; i++) {
        std::cout << std::fixed << std::setprecision(1) << homeworkScores[i];
        if (i < numHomeworks - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "  Average: " << std::fixed << std::setprecision(2) << getAverageScore() << std::endl;
}

// StudentNode implementation

StudentNode::StudentNode(Student* s) : student(s), next(nullptr) {}

StudentNode::~StudentNode() {
    // Delete the student object
    delete student;
}

// Linked list functions

void addStudent(StudentNode*& head, Student* student) {
    StudentNode* newNode = new StudentNode(student);
    newNode->next = head;
    head = newNode;
}

void addStudentToEnd(StudentNode*& head, Student* student) {
    StudentNode* newNode = new StudentNode(student);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    StudentNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void printAllStudents(StudentNode* head) {
    if (head == nullptr) {
        std::cout << "No students in the list." << std::endl;
        return;
    }
    
    std::cout << "\n=== Student List ===" << std::endl;
    StudentNode* current = head;
    int count = 1;
    
    while (current != nullptr) {
        std::cout << "\nStudent " << count << ":" << std::endl;
        current->student->print();
        current = current->next;
        count++;
    }
    std::cout << "\nTotal students: " << (count - 1) << std::endl;
}

void deleteList(StudentNode*& head) {
    while (head != nullptr) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int getListSize(StudentNode* head) {
    int count = 0;
    StudentNode* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}

Student* findStudent(StudentNode* head, int studentNumber) {
    StudentNode* current = head;
    
    while (current != nullptr) {
        if (current->student->studentNumber == studentNumber) {
            return current->student;
        }
        current = current->next;
    }
    
    return nullptr;
}
