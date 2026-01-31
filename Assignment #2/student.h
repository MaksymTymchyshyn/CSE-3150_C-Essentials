#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string name;
    int number;
    double* homeworkScores;
    int numHomework;
    
    Student();
    Student(const std::string& studentName, int studentNumber, int hwCount);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
};

void printStudent(const Student& student);
void printAllStudents(const std::vector<Student>& students);
Student inputStudent();

#endif
