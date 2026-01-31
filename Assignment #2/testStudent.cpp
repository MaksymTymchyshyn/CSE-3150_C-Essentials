#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "student.h"
#include <vector>

TEST_CASE("Student constructors") {
    SUBCASE("Default constructor") {
        Student s;
        CHECK(s.name == "");
        CHECK(s.number == 0);
        CHECK(s.numHomework == 0);
        CHECK(s.homeworkScores == nullptr);
    }
    
    SUBCASE("Parameterized constructor with homework") {
        Student s("Alice", 12345, 3);
        CHECK(s.name == "Alice");
        CHECK(s.number == 12345);
        CHECK(s.numHomework == 3);
        CHECK(s.homeworkScores != nullptr);
    }
    
    SUBCASE("Constructor with no homework") {
        Student s("Bob", 54321, 0);
        CHECK(s.numHomework == 0);
        CHECK(s.homeworkScores == nullptr);
    }
}

TEST_CASE("Copy constructor and assignment") {
    SUBCASE("Copy constructor") {
        Student s1("Charlie", 10001, 2);
        s1.homeworkScores[0] = 95.5;
        s1.homeworkScores[1] = 88.0;
        
        Student s2(s1);
        
        CHECK(s2.name == s1.name);
        CHECK(s2.homeworkScores[0] == 95.5);
        CHECK(s2.homeworkScores[1] == 88.0);
        CHECK(s2.homeworkScores != s1.homeworkScores);
    }
    
    SUBCASE("Assignment operator") {
        Student s1("David", 20002, 2);
        s1.homeworkScores[0] = 85.0;
        s1.homeworkScores[1] = 90.0;
        
        Student s2;
        s2 = s1;
        
        CHECK(s2.name == s1.name);
        CHECK(s2.homeworkScores[0] == 85.0);
        CHECK(s2.homeworkScores != s1.homeworkScores);
    }
}

TEST_CASE("Vector operations") {
    SUBCASE("Empty vector") {
        std::vector<Student> students;
        CHECK(students.empty());
    }
    
    SUBCASE("Multiple students") {
        std::vector<Student> students;
        students.push_back(Student("Emma", 30001, 1));
        students.push_back(Student("Frank", 30002, 2));
        
        CHECK(students.size() == 2);
        CHECK(students[0].name == "Emma");
        CHECK(students[1].name == "Frank");
    }
}

TEST_CASE("Edge cases") {
    SUBCASE("Empty name") {
        Student s("", 99999, 1);
        CHECK(s.name == "");
    }
    
    SUBCASE("Negative scores") {
        Student s("Grace", 40001, 2);
        s.homeworkScores[0] = -10.0;
        CHECK(s.homeworkScores[0] == -10.0);
    }
    
    SUBCASE("Many homework assignments") {
        Student s("Henry", 50001, 10);
        CHECK(s.numHomework == 10);
        for (int i = 0; i < 10; i++) {
            s.homeworkScores[i] = i * 10.0;
        }
        CHECK(s.homeworkScores[5] == 50.0);
    }
}
