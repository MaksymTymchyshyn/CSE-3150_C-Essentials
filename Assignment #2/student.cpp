#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student() : name(""), number(0), homeworkScores(nullptr), numHomework(0) {}

Student::Student(const std::string& studentName, int studentNumber, int hwCount)
    : name(studentName), number(studentNumber), numHomework(hwCount) {
    if (hwCount > 0) {
        homeworkScores = new double[hwCount];
        for (int i = 0; i < hwCount; i++) {
            homeworkScores[i] = 0.0;
        }
    } else {
        homeworkScores = nullptr;
    }
}

Student::Student(const Student& other) 
    : name(other.name), number(other.number), numHomework(other.numHomework) {
    if (other.numHomework > 0 && other.homeworkScores != nullptr) {
        homeworkScores = new double[other.numHomework];
        for (int i = 0; i < other.numHomework; i++) {
            homeworkScores[i] = other.homeworkScores[i];
        }
    } else {
        homeworkScores = nullptr;
    }
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] homeworkScores;
        name = other.name;
        number = other.number;
        numHomework = other.numHomework;
        
        if (other.numHomework > 0 && other.homeworkScores != nullptr) {
            homeworkScores = new double[other.numHomework];
            for (int i = 0; i < other.numHomework; i++) {
                homeworkScores[i] = other.homeworkScores[i];
            }
        } else {
            homeworkScores = nullptr;
        }
    }
    return *this;
}

Student::~Student() {
    delete[] homeworkScores;
}

void printStudent(const Student& student) {
    std::cout << "Student #" << student.number << ": " << student.name << std::endl;
    std::cout << "  Homework scores (" << student.numHomework << " assignments): ";
    
    if (student.numHomework == 0) {
        std::cout << "None";
    } else {
        std::cout << std::fixed << std::setprecision(2);
        for (int i = 0; i < student.numHomework; i++) {
            std::cout << student.homeworkScores[i];
            if (i < student.numHomework - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

void printAllStudents(const std::vector<Student>& students) {
    std::cout << "\n========== All Students ==========\n";
    if (students.empty()) {
        std::cout << "No students in the system.\n";
    } else {
        for (size_t i = 0; i < students.size(); i++) {
            printStudent(students[i]);
            std::cout << std::endl;
        }
    }
    std::cout << "==================================\n";
}

Student inputStudent() {
    std::string name;
    int number;
    int numHomework;
    
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter student number: ";
    std::cin >> number;
    
    std::cout << "Enter number of homework assignments: ";
    std::cin >> numHomework;
    
    Student student(name, number, numHomework);
    
    for (int i = 0; i < numHomework; i++) {
        std::cout << "Enter score for homework #" << (i + 1) << ": ";
        std::cin >> student.homeworkScores[i];
    }
    
    std::cin.ignore();
    
    return student;
}
