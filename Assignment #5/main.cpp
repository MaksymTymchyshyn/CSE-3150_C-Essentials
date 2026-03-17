#include <iostream>
#include "ComplexArray.h"

int main() {
    int n;
    std::cout << "How many complex numbers do you want to enter? ";
    std::cin >> n;

    ComplexArray arr(n);

    std::cout << "Enter each complex number as: real imaginary" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "  #" << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    std::cout << "\nOriginal array:" << std::endl;
    arr.print();

    // show move constructor
    ComplexArray moved(std::move(arr));
    std::cout << "\nAfter move constructor (new array):" << std::endl;
    moved.print();
    std::cout << "Old array size after move: " << arr.size() << std::endl;

    // show move assignment
    ComplexArray another(0);
    another = std::move(moved);
    std::cout << "\nAfter move assignment:" << std::endl;
    another.print();
    std::cout << "Moved-from size: " << moved.size() << std::endl;

    return 0;
}
