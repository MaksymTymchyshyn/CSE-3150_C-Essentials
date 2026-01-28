#include <iostream>
#include <cmath>

bool isPrime(int n) {
    // Handle edge cases
    if (n <= 1) {
        return false;
    }
    
    if (n == 2) {
        return true;
    }
    
    // Even numbers greater than 2 are not prime
    if (n % 2 == 0) {
        return false;
    }
    
    // Check odd divisors up to sqrt(n)
    int limit = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int number;
    
    std::cout << "Enter an integer to check if it's prime: ";
    std::cin >> number;
    
    if (isPrime(number)) {
        std::cout << number << " is a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }
    
    return 0;
}
