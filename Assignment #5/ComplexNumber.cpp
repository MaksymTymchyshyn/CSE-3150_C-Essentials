#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double r, double i) : real(r), imag(i) {}

void ComplexNumber::print() const {
    if (imag >= 0)
        std::cout << real << " + " << imag << "i";
    else
        std::cout << real << " - " << -imag << "i";
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return real == other.real && imag == other.imag;
}

// Read two doubles: real part then imaginary part
std::istream& operator>>(std::istream& in, ComplexNumber& c) {
    in >> c.real >> c.imag;
    return in;
}
