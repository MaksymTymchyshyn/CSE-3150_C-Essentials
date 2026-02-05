#include "Student.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    int numStudents;
    std::vector<Student> students;
    
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cin.ignore(); // Clear newline from buffer
    
    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int studentNumber;
        int numScores;
        
        std::cout << "\nEnter student " << (i + 1) << " information:" << std::endl;
        
        std::cout << "Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Student Number: ";
        std::cin >> studentNumber;
        
        std::cout << "Number of homework scores: ";
        std::cin >> numScores;
        
        Student student(name, studentNumber, numScores);
        
        // Enter homework scores
        for (int j = 0; j < numScores; j++) {
            std::cout << "Score " << (j + 1) << ": ";
            std::cin >> student.scores[j];
        }
        std::cin.ignore(); // Clear newline from buffer
        
        students.push_back(student);
    }
    
    // Print all students
    std::cout << "\n=== All Students ===" << std::endl << std::endl;
    for (const Student& student : students) {
        student.print();
    }
    
    return 0;
}
