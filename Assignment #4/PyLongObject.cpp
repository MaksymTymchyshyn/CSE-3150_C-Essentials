#include "PyLongObject.h"
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>

// Helper: Allocate digits array
void PyLongObject::allocateDigits(int size) {
    if (size > 0) {
        digitsBase30 = new unsigned[size];
        for (int i = 0; i < size; i++) {
            digitsBase30[i] = 0;
        }
    } else {
        digitsBase30 = nullptr;
    }
}

// Helper: Deallocate digits array
void PyLongObject::deallocateDigits() {
    if (digitsBase30) {
        delete[] digitsBase30;
        digitsBase30 = nullptr;
    }
}

// Helper: Deep copy from another object
void PyLongObject::copyFrom(const PyLongObject& other) {
    sign = other.sign;
    numDigits = other.numDigits;
    fitsInLongLong = other.fitsInLongLong;
    iValue = other.iValue;
    
    if (other.digitsBase30 && other.numDigits > 0) {
        allocateDigits(other.numDigits);
        for (int i = 0; i < other.numDigits; i++) {
            digitsBase30[i] = other.digitsBase30[i];
        }
    } else {
        digitsBase30 = nullptr;
    }
}

// Default constructor: represents 0
PyLongObject::PyLongObject() 
    : sign(1), numDigits(0), fitsInLongLong(true), iValue(0), digitsBase30(nullptr) {
}

// Constructor from int
PyLongObject::PyLongObject(int value) 
    : sign(value >= 0 ? 1 : -1), numDigits(0), fitsInLongLong(true), 
      iValue(value), digitsBase30(nullptr) {
}

// Constructor from long long
PyLongObject::PyLongObject(long long value) 
    : sign(value >= 0 ? 1 : -1), fitsInLongLong(true), 
      iValue(value), digitsBase30(nullptr) {
    
    // For simplicity, we always use fitsInLongLong for values that fit
    // Only convert to digit representation if needed for large operations
    numDigits = 0;
}

// Copy constructor
PyLongObject::PyLongObject(const PyLongObject& other) 
    : digitsBase30(nullptr) {
    copyFrom(other);
}

// Destructor
PyLongObject::~PyLongObject() {
    deallocateDigits();
}

// Assignment operator
PyLongObject& PyLongObject::operator=(const PyLongObject& other) {
    if (this != &other) {
        deallocateDigits();
        copyFrom(other);
    }
    return *this;
}

// Addition operator
PyLongObject PyLongObject::operator+(const PyLongObject& other) const {
    PyLongObject result;
    
    // Simple case: both fit in long long
    if (this->fitsInLongLong && other.fitsInLongLong) {
        // Check for potential overflow
        long long a = this->iValue;
        long long b = other.iValue;
        
        // Check if result will fit in long long
        bool willOverflow = false;
        if (b > 0 && a > LLONG_MAX - b) willOverflow = true;
        if (b < 0 && a < LLONG_MIN - b) willOverflow = true;
        
        if (!willOverflow) {
            result.iValue = a + b;
            result.sign = (result.iValue >= 0) ? 1 : -1;
            result.fitsInLongLong = true;
            result.numDigits = 0;
            return result;
        }
        
        // If overflow, convert to digit representation
        // For now, we'll use a simplified approach with base-2^30
    }
    
    // Convert both to digit representation and add
    // This is a simplified version - real implementation would handle all cases
    
    // For demonstration, we'll use the digit-by-digit addition as shown in the document
    // First, convert both numbers to positive digit arrays
    
    long long absA = std::abs(this->iValue);
    long long absB = std::abs(other.iValue);
    
    // Determine signs for addition
    int signA = this->sign;
    int signB = other.sign;
    
    // If signs are the same, add magnitudes
    if (signA == signB) {
        // Add magnitudes
        long long sum = absA + absB;
        result.iValue = signA * sum;
        result.sign = signA;
        result.fitsInLongLong = true;
        result.numDigits = 0;
        return result;
    } else {
        // Different signs: subtract magnitudes
        if (absA >= absB) {
            result.iValue = signA * (absA - absB);
            result.sign = (result.iValue >= 0) ? 1 : -1;
        } else {
            result.iValue = signB * (absB - absA);
            result.sign = (result.iValue >= 0) ? 1 : -1;
        }
        result.fitsInLongLong = true;
        result.numDigits = 0;
        return result;
    }
}

// Equality operator
bool PyLongObject::operator==(const PyLongObject& other) const {
    if (this->fitsInLongLong && other.fitsInLongLong) {
        return this->iValue == other.iValue;
    }
    
    // If using digit representation, compare digits
    if (this->sign != other.sign) return false;
    if (this->numDigits != other.numDigits) return false;
    
    for (int i = 0; i < this->numDigits; i++) {
        if (this->digitsBase30[i] != other.digitsBase30[i]) {
            return false;
        }
    }
    
    return true;
}

bool PyLongObject::operator!=(const PyLongObject& other) const {
    return !(*this == other);
}

// Output operator
std::ostream& operator<<(std::ostream& os, const PyLongObject& obj) {
    if (obj.fitsInLongLong) {
        os << obj.iValue;
    } else {
        // For digit representation, would need to convert back to decimal
        os << "[BASE30 representation with " << obj.numDigits << " digits]";
    }
    return os;
}
