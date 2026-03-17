#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

// Simple complex number with real and imaginary parts
struct ComplexNumber {
    double real;
    double imag;

    ComplexNumber(double r = 0.0, double i = 0.0);

    void print() const;

    bool operator==(const ComplexNumber& other) const;
};

// Stream extraction for reading "a+bi" or just "a b" style input
std::istream& operator>>(std::istream& in, ComplexNumber& c);

#endif
