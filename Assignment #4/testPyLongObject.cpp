#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "doctest.h" 

#include "PyLongObject.h"

TEST_CASE("testing constructor with zero") { 
    PyLongObject pyLongObject(0);
    CHECK(pyLongObject.getSmallValue() == 0);
    CHECK(pyLongObject.fitsInLongLong == true);
    CHECK(pyLongObject.sign == 1);
}

TEST_CASE("testing constructor with positive value") {
    PyLongObject pyLongObject(42);
    CHECK(pyLongObject.getSmallValue() == 42);
    CHECK(pyLongObject.fitsInLongLong == true);
    CHECK(pyLongObject.sign == 1);
}

TEST_CASE("testing constructor with negative value") {
    PyLongObject pyLongObject(-42);
    CHECK(pyLongObject.getSmallValue() == -42);
    CHECK(pyLongObject.fitsInLongLong == true);
    CHECK(pyLongObject.sign == -1);
}

TEST_CASE("testing copy constructor") {
    PyLongObject original(123);
    PyLongObject copy(original);
    CHECK(copy.getSmallValue() == 123);
    CHECK(copy == original);
}

TEST_CASE("testing equality operator") {
    PyLongObject a(100);
    PyLongObject b(100);
    PyLongObject c(200);
    
    CHECK(a == b);
    CHECK(!(a == c));
}

TEST_CASE("testing addition with small values") {
    PyLongObject a(10);
    PyLongObject b(20);
    PyLongObject result = a + b;
    
    CHECK(result.getSmallValue() == 30);
}

TEST_CASE("testing addition with zero") {
    PyLongObject a(42);
    PyLongObject zero(0);
    PyLongObject result = a + zero;
    
    CHECK(result.getSmallValue() == 42);
}

TEST_CASE("testing addition with negative values") {
    PyLongObject a(50);
    PyLongObject b(-30);
    PyLongObject result = a + b;
    
    CHECK(result.getSmallValue() == 20);
}

TEST_CASE("testing self equality") {
    PyLongObject a(999);
    CHECK(a == a);
}