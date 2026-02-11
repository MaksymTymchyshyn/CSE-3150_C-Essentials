#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "Student.h"

// Edge Cases Tested:
// 1. Empty list, 2. Single student, 3. Zero/one homework
// 4. Multiple students, 5. Search operations, 6. Memory management

TEST_CASE("Student: Constructor with zero homeworks") {
    Student student("Alice", 101, 0);
    
    CHECK(student.name == "Alice");
    CHECK(student.studentNumber == 101);
    CHECK(student.numHomeworks == 0);
    CHECK(student.homeworkScores != nullptr);  // Should still allocate
    CHECK(student.getAverageScore() == 0.0);
}

TEST_CASE("Student: Constructor with homeworks and score setting") {
    Student student("Bob", 102, 3);
    
    CHECK(student.name == "Bob");
    CHECK(student.studentNumber == 102);
    CHECK(student.numHomeworks == 3);
    
    student.homeworkScores[0] = 85.5;
    student.homeworkScores[1] = 90.0;
    student.homeworkScores[2] = 92.5;
    
    CHECK(student.homeworkScores[0] == 85.5);
    CHECK(student.homeworkScores[1] == 90.0);
    CHECK(student.homeworkScores[2] == 92.5);
}

TEST_CASE("Student: Average score calculations") {
    Student student1("Diana", 104, 4);
    student1.homeworkScores[0] = 80.0;
    student1.homeworkScores[1] = 90.0;
    student1.homeworkScores[2] = 85.0;
    student1.homeworkScores[3] = 95.0;
    CHECK(student1.getAverageScore() == 87.5);
    
    // Edge case: one homework
    Student student2("Eve", 105, 1);
    student2.homeworkScores[0] = 100.0;
    CHECK(student2.getAverageScore() == 100.0);
}

TEST_CASE("Student: Copy constructor deep copy") {
    Student original("Frank", 106, 3);
    original.homeworkScores[0] = 70.0;
    original.homeworkScores[1] = 80.0;
    original.homeworkScores[2] = 90.0;
    
    Student copy(original);
    
    // Check values are copied
    CHECK(copy.name == "Frank");
    CHECK(copy.studentNumber == 106);
    CHECK(copy.numHomeworks == 3);
    CHECK(copy.homeworkScores[0] == 70.0);
    CHECK(copy.homeworkScores[1] == 80.0);
    CHECK(copy.homeworkScores[2] == 90.0);
    
    // Verify deep copy - arrays should be separate
    CHECK(copy.homeworkScores != original.homeworkScores);
    
    // Modify copy, shouldn't affect original
    copy.homeworkScores[0] = 100.0;
    CHECK(original.homeworkScores[0] == 70.0);
}

TEST_CASE("Student: Assignment operator") {
    Student s1("George", 107, 2);
    s1.homeworkScores[0] = 85.0;
    s1.homeworkScores[1] = 95.0;
    
    Student s2("Hannah", 108, 3);
    s2 = s1;
    
    // Check assignment worked
    CHECK(s2.name == "George");
    CHECK(s2.studentNumber == 107);
    CHECK(s2.numHomeworks == 2);
    CHECK(s2.homeworkScores[0] == 85.0);
    CHECK(s2.homeworkScores[1] == 95.0);
    
    // Verify deep copy
    CHECK(s2.homeworkScores != s1.homeworkScores);
}

TEST_CASE("Linked List: Empty list operations") {
    StudentNode* list = nullptr;
    
    CHECK(getListSize(list) == 0);
    CHECK(findStudent(list, 100) == nullptr);
    printAllStudents(list);  // Should not crash
    deleteList(list);  // Should not crash
}

TEST_CASE("Linked List: Add single student") {
    StudentNode* list = nullptr;
    
    Student* s1 = new Student("Ivan", 201, 2);
    s1->homeworkScores[0] = 88.0;
    s1->homeworkScores[1] = 92.0;
    
    addStudent(list, s1);
    
    CHECK(list != nullptr);
    CHECK(getListSize(list) == 1);
    CHECK(list->student->name == "Ivan");
    CHECK(list->student->studentNumber == 201);
    
    deleteList(list);
    CHECK(list == nullptr);
}

TEST_CASE("Linked List: Add and find students") {
    StudentNode* list = nullptr;
    
    Student* s1 = new Student("Alice", 301, 1);
    Student* s2 = new Student("Bob", 302, 1);
    Student* s3 = new Student("Charlie", 303, 1);
    
    addStudentToEnd(list, s1);
    addStudentToEnd(list, s2);
    addStudentToEnd(list, s3);
    
    CHECK(getListSize(list) == 3);
    CHECK(list->student->name == "Alice");
    
    // Find existing student
    Student* found = findStudent(list, 302);
    CHECK(found != nullptr);
    CHECK(found->name == "Bob");
    
    // Find non-existing student
    CHECK(findStudent(list, 999) == nullptr);
    
    deleteList(list);
}

TEST_CASE("Linked List: Students with different homework counts") {
    StudentNode* list = nullptr;
    
    Student* s1 = new Student("Student1", 401, 0);
    Student* s2 = new Student("Student2", 402, 1);
    s2->homeworkScores[0] = 100.0;
    Student* s3 = new Student("Student3", 403, 3);
    for (int i = 0; i < 3; i++) {
        s3->homeworkScores[i] = 80.0 + i * 5;
    }
    
    addStudentToEnd(list, s1);
    addStudentToEnd(list, s2);
    addStudentToEnd(list, s3);
    
    CHECK(getListSize(list) == 3);
    CHECK(list->student->numHomeworks == 0);
    CHECK(list->student->getAverageScore() == 0.0);
    CHECK(list->next->student->getAverageScore() == 100.0);
    
    deleteList(list);
}

TEST_CASE("Memory: Self-assignment") {
    Student s1("Test", 501, 2);
    s1.homeworkScores[0] = 75.0;
    s1.homeworkScores[1] = 85.0;
    
    s1 = s1;  // Self-assignment should be safe
    
    CHECK(s1.name == "Test");
    CHECK(s1.homeworkScores[0] == 75.0);
}
