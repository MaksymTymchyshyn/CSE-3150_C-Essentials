#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Student.h"
#include <vector>

TEST_CASE("Student with zero homework scores") {
    Student student("John Doe", 12345, 0);
    CHECK(student.name == "John Doe");
    CHECK(student.studentNumber == 12345);
    CHECK(student.numScores == 0);
}

TEST_CASE("Student with one homework score") {
    Student student("Jane Smith", 54321, 1);
    student.scores[0] = 95.5;
    CHECK(student.numScores == 1);
    CHECK(student.scores[0] == 95.5);
}

TEST_CASE("Student with multiple homework scores") {
    Student student("Bob Johnson", 11111, 5);
    student.scores[0] = 85.0;
    student.scores[1] = 90.0;
    student.scores[2] = 88.5;
    student.scores[3] = 92.0;
    student.scores[4] = 87.5;
    
    CHECK(student.numScores == 5);
    CHECK(student.scores[0] == 85.0);
    CHECK(student.scores[4] == 87.5);
}

TEST_CASE("Empty student name") {
    Student student("", 99999, 3);
    CHECK(student.name == "");
    CHECK(student.studentNumber == 99999);
}

TEST_CASE("Vector with zero students") {
    std::vector<Student> students;
    CHECK(students.size() == 0);
}

TEST_CASE("Vector with one student") {
    std::vector<Student> students;
    Student student("Alice Brown", 22222, 3);
    students.push_back(student);
    CHECK(students.size() == 1);
    CHECK(students[0].name == "Alice Brown");
}

TEST_CASE("Vector with multiple students") {
    std::vector<Student> students;
    Student s1("Student One", 10001, 2);
    Student s2("Student Two", 10002, 3);
    Student s3("Student Three", 10003, 1);
    
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);
    
    CHECK(students.size() == 3);
    CHECK(students[0].studentNumber == 10001);
    CHECK(students[1].studentNumber == 10002);
    CHECK(students[2].studentNumber == 10003);
}

TEST_CASE("Large number of homework scores") {
    Student student("Test Student", 12345, 100);
    CHECK(student.numScores == 100);
    
    // Set and verify a few scores
    student.scores[0] = 100.0;
    student.scores[50] = 75.5;
    student.scores[99] = 88.0;
    
    CHECK(student.scores[0] == 100.0);
    CHECK(student.scores[50] == 75.5);
    CHECK(student.scores[99] == 88.0);
}
