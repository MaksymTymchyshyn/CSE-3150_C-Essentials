#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int studentNumber;
    double* scores;
    int numScores;
    
    // Constructor
    Student(std::string studentName, int number, int numberOfScores);
    
    // Copy Constructor
    Student(const Student& other);
    
    // Assignment Operator
    Student& operator=(const Student& other);
    
    // Destructor
    ~Student();
    
    // Print student information
    void print() const;
};

#endif
