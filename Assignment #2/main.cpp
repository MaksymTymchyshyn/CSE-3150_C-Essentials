#include <iostream>
#include <vector>
#include <limits>
#include "student.h"

int main() {
    std::vector<Student> students;
    
    std::cout << "=== Student Management System ===\n";
    std::cout << "Enter students (Press Ctrl-D to finish)\n\n";
    
    while (true) {
        std::cout << "--- New Student ---\n";
        
        if (std::cin.eof()) {
            std::cout << "\n\nInput terminated.\n";
            break;
        }
        
        try {
            Student student = inputStudent();
            students.push_back(student);
            std::cout << "\nStudent added successfully!\n\n";
        } catch (const std::exception& e) {
            if (std::cin.eof()) {
                std::cout << "\n\nInput terminated.\n";
                break;
            }
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    printAllStudents(students);
    std::cout << "\nTotal students: " << students.size() << std::endl;
    
    return 0;
}
