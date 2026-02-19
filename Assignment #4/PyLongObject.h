#ifndef PYLONGOBJECT_H
#define PYLONGOBJECT_H

#include <iostream>

/**
 * @brief Python-style arbitrary precision integer
 * 
 * This class implements a simplified version of CPython's PyLongObject.
 * Integers are represented in base 2^30 to allow for arbitrarily large values.
 * 
 * For small integers that fit in a long long, we store them directly.
 * For larger integers, we use a dynamic array of digits in base 2^30.
 */
class PyLongObject {
private:
    int sign;                    // +1 or -1 (0 is represented as +1 with value 0)
    int numDigits;               // Number of base-2^30 digits
    bool fitsInLongLong;         // True if value fits in long long
    long long iValue;            // Direct value if fitsInLongLong is true
    unsigned* digitsBase30;      // Array of digits in base 2^30

    static const unsigned BASE = 1073741824u;  // 2^30
    static const int DIGIT_BITS = 30;

    // Helper functions
    void allocateDigits(int size);
    void deallocateDigits();
    void copyFrom(const PyLongObject& other);
    
public:
    // Constructors
    PyLongObject();                              // Default constructor
    PyLongObject(long long value);               // Constructor from long long
    PyLongObject(int value);                     // Constructor from int
    PyLongObject(const PyLongObject& other);     // Copy constructor
    
    // Destructor
    ~PyLongObject();
    
    // Assignment operator
    PyLongObject& operator=(const PyLongObject& other);
    
    // Arithmetic operators
    PyLongObject operator+(const PyLongObject& other) const;
    
    // Equality operator for testing
    bool operator==(const PyLongObject& other) const;
    bool operator!=(const PyLongObject& other) const;
    
    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const PyLongObject& obj);
    
    // Getters for testing
    int getSign() const { return sign; }
    int getNumDigits() const { return numDigits; }
    bool getFitsInLongLong() const { return fitsInLongLong; }
    long long getIValue() const { return iValue; }
    unsigned getDigitAt(int i) const { 
        return (i >= 0 && i < numDigits && digitsBase30) ? digitsBase30[i] : 0; 
    }
};

#endif // PYLONGOBJECT_H
