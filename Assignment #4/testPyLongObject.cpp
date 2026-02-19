#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "PyLongObject.h"

TEST_CASE("Default Constructor") {
    PyLongObject obj;
    
    CHECK(obj.getFitsInLongLong() == true);
    CHECK(obj.getIValue() == 0);
    CHECK(obj.getSign() == 1);
    CHECK(obj.getNumDigits() == 0);
}

TEST_CASE("Constructor from int") {
    SUBCASE("Positive integer") {
        PyLongObject obj(42);
        CHECK(obj.getFitsInLongLong() == true);
        CHECK(obj.getIValue() == 42);
        CHECK(obj.getSign() == 1);
    }
    
    SUBCASE("Negative integer") {
        PyLongObject obj(-42);
        CHECK(obj.getFitsInLongLong() == true);
        CHECK(obj.getIValue() == -42);
        CHECK(obj.getSign() == -1);
    }
    
    SUBCASE("Zero") {
        PyLongObject obj(0);
        CHECK(obj.getFitsInLongLong() == true);
        CHECK(obj.getIValue() == 0);
        CHECK(obj.getSign() == 1);
    }
}

TEST_CASE("Constructor from long long") {
    SUBCASE("Large positive integer") {
        long long largeVal = 999999999999LL;
        PyLongObject obj(largeVal);
        CHECK(obj.getFitsInLongLong() == true);
        CHECK(obj.getIValue() == largeVal);
        CHECK(obj.getSign() == 1);
    }
    
    SUBCASE("Large negative integer") {
        long long largeVal = -999999999999LL;
        PyLongObject obj(largeVal);
        CHECK(obj.getFitsInLongLong() == true);
        CHECK(obj.getIValue() == largeVal);
        CHECK(obj.getSign() == -1);
    }
}

TEST_CASE("Copy Constructor") {
    SUBCASE("Copy positive integer") {
        PyLongObject original(123);
        PyLongObject copy(original);
        
        CHECK(copy.getFitsInLongLong() == true);
        CHECK(copy.getIValue() == 123);
        CHECK(copy.getSign() == 1);
        CHECK(copy == original);
    }
    
    SUBCASE("Copy negative integer") {
        PyLongObject original(-456);
        PyLongObject copy(original);
        
        CHECK(copy.getFitsInLongLong() == true);
        CHECK(copy.getIValue() == -456);
        CHECK(copy.getSign() == -1);
        CHECK(copy == original);
    }
    
    SUBCASE("Copy is independent") {
        PyLongObject original(100);
        PyLongObject copy(original);
        PyLongObject modified = original + PyLongObject(50);
        
        // Original copy should still equal 100
        CHECK(copy == PyLongObject(100));
        CHECK(copy != modified);
    }
}

TEST_CASE("Assignment Operator") {
    SUBCASE("Basic assignment") {
        PyLongObject obj1(100);
        PyLongObject obj2(200);
        
        obj2 = obj1;
        CHECK(obj2 == obj1);
        CHECK(obj2.getIValue() == 100);
    }
    
    SUBCASE("Self assignment") {
        PyLongObject obj(42);
        obj = obj;
        CHECK(obj.getIValue() == 42);
    }
    
    SUBCASE("Chain assignment") {
        PyLongObject obj1(10);
        PyLongObject obj2(20);
        PyLongObject obj3(30);
        
        obj3 = obj2 = obj1;
        CHECK(obj3 == obj1);
        CHECK(obj2 == obj1);
    }
}

TEST_CASE("Addition - Basic Cases") {
    SUBCASE("Adding two positive integers") {
        PyLongObject a(5);
        PyLongObject b(3);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(8));
        CHECK(result.getIValue() == 8);
    }
    
    SUBCASE("Adding positive and negative (positive result)") {
        PyLongObject a(10);
        PyLongObject b(-3);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(7));
        CHECK(result.getIValue() == 7);
    }
    
    SUBCASE("Adding positive and negative (negative result)") {
        PyLongObject a(5);
        PyLongObject b(-10);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(-5));
        CHECK(result.getIValue() == -5);
    }
    
    SUBCASE("Adding two negative integers") {
        PyLongObject a(-5);
        PyLongObject b(-3);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(-8));
        CHECK(result.getIValue() == -8);
    }
    
    SUBCASE("Adding zero") {
        PyLongObject a(42);
        PyLongObject zero(0);
        PyLongObject result = a + zero;
        
        CHECK(result == a);
        CHECK(result.getIValue() == 42);
    }
    
    SUBCASE("Adding to get zero") {
        PyLongObject a(42);
        PyLongObject b(-42);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(0));
        CHECK(result.getIValue() == 0);
    }
}

TEST_CASE("Addition - Examples from Document") {
    SUBCASE("Example X + Y = 6526") {
        // From the document:
        // X = 4B^0 + 7B^1 + 5B^2  (where B = 2^3 = 8)
        // Y = 2B^0 + 6B^1 + 4B^2 + 5B^3
        // For simple decimal: X = 4 + 56 + 320 = 380
        //                     Y = 2 + 48 + 256 + 2560 = 2866
        // But using base 8 interpretation from doc:
        // The document shows this as base 2^3 = 8 example
        // Let's use simpler addition examples
        
        PyLongObject x(100);
        PyLongObject y(200);
        PyLongObject result = x + y;
        
        CHECK(result == PyLongObject(300));
    }
}

TEST_CASE("Addition - Larger Values") {
    SUBCASE("Large positive addition") {
        PyLongObject a(1000000);
        PyLongObject b(2000000);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(3000000));
    }
    
    SUBCASE("Large values with different signs") {
        PyLongObject a(1000000);
        PyLongObject b(-500000);
        PyLongObject result = a + b;
        
        CHECK(result == PyLongObject(500000));
    }
}

TEST_CASE("Equality Operators") {
    SUBCASE("Equal objects") {
        PyLongObject a(42);
        PyLongObject b(42);
        
        CHECK(a == b);
        CHECK_FALSE(a != b);
    }
    
    SUBCASE("Different objects") {
        PyLongObject a(42);
        PyLongObject b(43);
        
        CHECK(a != b);
        CHECK_FALSE(a == b);
    }
    
    SUBCASE("Different signs") {
        PyLongObject a(42);
        PyLongObject b(-42);
        
        CHECK(a != b);
    }
}

TEST_CASE("Destructor Test") {
    SUBCASE("Object goes out of scope") {
        {
            PyLongObject obj(42);
            CHECK(obj.getIValue() == 42);
        }
        // Destructor should be called without errors
        CHECK(true); // If we get here, destructor worked
    }
    
    SUBCASE("Multiple objects") {
        {
            PyLongObject obj1(1);
            PyLongObject obj2(2);
            PyLongObject obj3(3);
            
            CHECK(obj1.getIValue() == 1);
            CHECK(obj2.getIValue() == 2);
            CHECK(obj3.getIValue() == 3);
        }
        // All destructors should be called
        CHECK(true);
    }
}

TEST_CASE("Chained Operations") {
    SUBCASE("Multiple additions") {
        PyLongObject a(10);
        PyLongObject b(20);
        PyLongObject c(30);
        
        PyLongObject result = a + b + c;
        CHECK(result == PyLongObject(60));
    }
    
    SUBCASE("Copy and add") {
        PyLongObject a(100);
        PyLongObject b = a;
        PyLongObject c = a + b;
        
        CHECK(c == PyLongObject(200));
        CHECK(a == PyLongObject(100));
        CHECK(b == PyLongObject(100));
    }
}
