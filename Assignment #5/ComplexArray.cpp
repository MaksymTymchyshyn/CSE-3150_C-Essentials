#include "ComplexArray.h"
#include <stdexcept>

ComplexArray::ComplexArray(int size) : size_(size) {
    if (size_ > 0)
        data_ = new ComplexNumber[size_];
    else
        data_ = nullptr;
}

// move constructor: steal the pointer
ComplexArray::ComplexArray(ComplexArray&& other) noexcept
    : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
}

// move assignment: free our stuff, then steal from other
ComplexArray& ComplexArray::operator=(ComplexArray&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

ComplexArray::~ComplexArray() {
    delete[] data_;
}

int ComplexArray::size() const { return size_; }

ComplexNumber& ComplexArray::operator[](int index) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("index out of range");
    return data_[index];
}

const ComplexNumber& ComplexArray::operator[](int index) const {
    if (index < 0 || index >= size_)
        throw std::out_of_range("index out of range");
    return data_[index];
}

void ComplexArray::print() const {
    for (int i = 0; i < size_; i++) {
        std::cout << "  [" << i << "] ";
        data_[i].print();
        std::cout << "\n";
    }
}
