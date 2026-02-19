#include <iostream>
#include <cmath>
#include <cstdlib>

#include "PyLongObject.h"

// Constructor
PyLongObject::PyLongObject(long long _iValue) {
    iValue = _iValue;
    fitsInLongLong = true;
    digitsBase30 = nullptr;
    numDigits = 0;
    
    if (_iValue >= 0) {
        sign = 1;
    } else {
        sign = -1;
    }
}

// Copy constructor
PyLongObject::PyLongObject(const PyLongObject & other) {
    sign = other.sign;
    numDigits = other.numDigits;
    fitsInLongLong = other.fitsInLongLong;
    iValue = other.iValue;
    
    if (other.digitsBase30 != nullptr && other.numDigits > 0) {
        digitsBase30 = new unsigned[numDigits];
        for (int i = 0; i < numDigits; i++) {
            digitsBase30[i] = other.digitsBase30[i];
        }
    } else {
        digitsBase30 = nullptr;
    }
}

// Destructor
PyLongObject::~PyLongObject() {
    if (digitsBase30 != nullptr) {
        delete[] digitsBase30;
        digitsBase30 = nullptr;
    }
}

int PyLongObject::getDigitN(int n) const {  // returns -1 on failure
    if (n > numDigits && !fitsInLongLong) {
        return -1;
    } else {
        return digitsBase30[n];
    }
}

long long PyLongObject::getSmallValue() {
    if (fitsInLongLong) {
        return iValue;
    } else {
        return -1;
    }
}

bool PyLongObject::operator==(const PyLongObject & other) const {
    if (this == &other) {
        return true;
    }
    
    if (fitsInLongLong != other.fitsInLongLong) return false;
    
    if (fitsInLongLong && other.fitsInLongLong) {
        return iValue == other.iValue;
    }
    
    if (!fitsInLongLong && !other.fitsInLongLong) {
        if (numDigits != other.numDigits) return false;
        if (sign != other.sign) return false;
        
        for (int i = 0; i < numDigits; i++) {
            if (digitsBase30[i] != other.digitsBase30[i]) {
                return false;
            }
        }
        return true;
    }
    
    return false;
}

// Addition operator (simplified for long long values that fit)
PyLongObject PyLongObject::operator+(const PyLongObject & other) const {
    // Simple implementation for values that fit in long long
    if (fitsInLongLong && other.fitsInLongLong) {
        return PyLongObject(iValue + other.iValue);
    }
    
    // For now, return a simple result for complex cases
    // A full implementation would handle base-2^30 digit arithmetic
    return PyLongObject(0);
}

ostream & operator<<(ostream & os, const PyLongObject & pyLongObject) {
    if (pyLongObject.fitsInLongLong) {
        os << pyLongObject.iValue;
    } else {
        // For large numbers, print a simplified representation
        os << "PyLong(";
        if (pyLongObject.sign == -1) os << "-";
        os << "numDigits=" << pyLongObject.numDigits << ")";
    }
    return os;
};