#ifndef COMPLEXARRAY_H
#define COMPLEXARRAY_H

#include "ComplexNumber.h"

// Holds a dynamically allocated array of ComplexNumber objects.
// No copy allowed, only move semantics.
class ComplexArray {
public:
    explicit ComplexArray(int size);

    // disable copying
    ComplexArray(const ComplexArray&) = delete;
    ComplexArray& operator=(const ComplexArray&) = delete;

    // move constructor and move assignment
    ComplexArray(ComplexArray&& other) noexcept;
    ComplexArray& operator=(ComplexArray&& other) noexcept;

    ~ComplexArray();

    int size() const;
    ComplexNumber& operator[](int index);
    const ComplexNumber& operator[](int index) const;
    void print() const;

private:
    ComplexNumber* data_;
    int size_;
};

#endif
