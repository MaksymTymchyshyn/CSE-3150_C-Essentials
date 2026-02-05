#include "Student.h"
#include <iostream>

// Constructor - dynamically allocates array for homework scores
Student::Student(std::string studentName, int number, int numberOfScores) {
    name = studentName;
    studentNumber = number;
    numScores = numberOfScores;
    scores = new double[numScores];
    
    // Initialize scores to 0
    for (int i = 0; i < numScores; i++) {
        scores[i] = 0.0;
    }
}

// Copy Constructor - performs deep copy
Student::Student(const Student& other) {
    name = other.name;
    studentNumber = other.studentNumber;
    numScores = other.numScores;
    scores = new double[numScores];
    
    // Copy scores
    for (int i = 0; i < numScores; i++) {
        scores[i] = other.scores[i];
    }
}

// Assignment Operator - performs deep copy
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        // Delete old array
        delete[] scores;
        
        // Copy data
        name = other.name;
        studentNumber = other.studentNumber;
        numScores = other.numScores;
        
        // Allocate and copy new array
        scores = new double[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
    }
    return *this;
}

// Destructor - deallocates the dynamic array
Student::~Student() {
    delete[] scores;
}

// Print student information
void Student::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Student Number: " << studentNumber << std::endl;
    std::cout << "Scores: ";
    for (int i = 0; i < numScores; i++) {
        std::cout << scores[i];
        if (i < numScores - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl << std::endl;
}
