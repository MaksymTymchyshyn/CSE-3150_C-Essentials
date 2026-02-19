#include "PyLongObject.h"
#include <iostream>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Assignment #4: Python Style Integers" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;
    
    // Demonstrate default constructor
    std::cout << "1. Default Constructor:" << std::endl;
    PyLongObject zero;
    std::cout << "   zero = " << zero << std::endl << std::endl;
    
    // Demonstrate int constructor
    std::cout << "2. Constructor from int:" << std::endl;
    PyLongObject a(42);
    PyLongObject b(-17);
    std::cout << "   a = " << a << std::endl;
    std::cout << "   b = " << b << std::endl << std::endl;
    
    // Demonstrate long long constructor
    std::cout << "3. Constructor from long long:" << std::endl;
    PyLongObject large(999999999999LL);
    std::cout << "   large = " << large << std::endl << std::endl;
    
    // Demonstrate copy constructor
    std::cout << "4. Copy Constructor:" << std::endl;
    PyLongObject copy_a(a);
    std::cout << "   original a = " << a << std::endl;
    std::cout << "   copy of a  = " << copy_a << std::endl;
    std::cout << "   Are they equal? " << (copy_a == a ? "Yes" : "No") << std::endl << std::endl;
    
    // Demonstrate assignment operator
    std::cout << "5. Assignment Operator:" << std::endl;
    PyLongObject x(100);
    PyLongObject y(200);
    std::cout << "   Before: x = " << x << ", y = " << y << std::endl;
    x = y;
    std::cout << "   After x = y: x = " << x << ", y = " << y << std::endl << std::endl;
    
    // Demonstrate addition
    std::cout << "6. Addition Operator:" << std::endl;
    
    PyLongObject num1(25);
    PyLongObject num2(17);
    PyLongObject sum1 = num1 + num2;
    std::cout << "   " << num1 << " + " << num2 << " = " << sum1 << std::endl;
    
    PyLongObject num3(50);
    PyLongObject num4(-30);
    PyLongObject sum2 = num3 + num4;
    std::cout << "   " << num3 << " + " << num4 << " = " << sum2 << std::endl;
    
    PyLongObject num5(-15);
    PyLongObject num6(-25);
    PyLongObject sum3 = num5 + num6;
    std::cout << "   " << num5 << " + " << num6 << " = " << sum3 << std::endl;
    
    PyLongObject num7(100);
    PyLongObject num8(-100);
    PyLongObject sum4 = num7 + num8;
    std::cout << "   " << num7 << " + " << num8 << " = " << sum4 << std::endl << std::endl;
    
    // Demonstrate chained operations
    std::cout << "7. Chained Operations:" << std::endl;
    PyLongObject p(10);
    PyLongObject q(20);
    PyLongObject r(30);
    PyLongObject total = p + q + r;
    std::cout << "   " << p << " + " << q << " + " << r << " = " << total << std::endl << std::endl;
    
    // Example from the document (simplified)
    std::cout << "8. Document Example (simplified):" << std::endl;
    std::cout << "   From the Python Style Integers paper:" << std::endl;
    std::cout << "   Base-2^30 representation allows arbitrarily large integers." << std::endl;
    std::cout << "   For small values, we use direct long long storage." << std::endl;
    std::cout << "   For large values, digit array would be used." << std::endl << std::endl;
    
    PyLongObject val1(6526);
    std::cout << "   Example value: " << val1 << std::endl;
    PyLongObject val2(1000);
    PyLongObject val3(5526);
    PyLongObject check = val2 + val3;
    std::cout << "   Verification: " << val2 << " + " << val3 << " = " << check << std::endl;
    std::cout << "   Does it equal " << val1 << "? " << (check == val1 ? "Yes" : "No") << std::endl << std::endl;
    
    std::cout << "========================================" << std::endl;
    std::cout << "All operations completed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}
