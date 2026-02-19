#ifndef _PYLONGOBJECT_H
#define _PYLONGOBJECT_H

#include <iostream>

using namespace std;

struct PyLongObject {
    // Constructors
    PyLongObject(long long _iValue);
    PyLongObject(const PyLongObject & other); // Copy constructor
    
    // Destructor
    ~PyLongObject();

    int sign; // +1 or -1.
    int numDigits;
    bool fitsInLongLong;
    long long iValue;

    int getDigitN(int n) const;  // returns -1 on failure
    long long getSmallValue();

    bool operator==(const PyLongObject & other) const;
    PyLongObject operator+(const PyLongObject & other) const; // Addition operator

    unsigned *digitsBase30;
};

#endif