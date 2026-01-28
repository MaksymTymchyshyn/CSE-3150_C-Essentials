#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
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

TEST_CASE("testing prime number function - edge cases") {
    // Negative numbers are not prime
    CHECK(isPrime(-5) == false);
    CHECK(isPrime(-1) == false);
    
    // Zero and one are not prime
    CHECK(isPrime(0) == false);
    CHECK(isPrime(1) == false);
    
    // Two is the only even prime
    CHECK(isPrime(2) == true);
}

TEST_CASE("testing small prime numbers") {
    CHECK(isPrime(3) == true);
    CHECK(isPrime(5) == true);
    CHECK(isPrime(7) == true);
    CHECK(isPrime(11) == true);
    CHECK(isPrime(13) == true);
    CHECK(isPrime(17) == true);
    CHECK(isPrime(19) == true);
    CHECK(isPrime(23) == true);
    CHECK(isPrime(29) == true);
    CHECK(isPrime(31) == true);
}

TEST_CASE("testing small composite numbers") {
    CHECK(isPrime(4) == false);
    CHECK(isPrime(6) == false);
    CHECK(isPrime(8) == false);
    CHECK(isPrime(9) == false);
    CHECK(isPrime(10) == false);
    CHECK(isPrime(12) == false);
    CHECK(isPrime(15) == false);
    CHECK(isPrime(21) == false);
    CHECK(isPrime(25) == false);
    CHECK(isPrime(27) == false);
}

TEST_CASE("testing larger prime numbers") {
    CHECK(isPrime(97) == true);
    CHECK(isPrime(101) == true);
    CHECK(isPrime(103) == true);
    CHECK(isPrime(107) == true);
    CHECK(isPrime(109) == true);
}

TEST_CASE("testing larger composite numbers") {
    CHECK(isPrime(100) == false);
    CHECK(isPrime(121) == false);  // 11 * 11
    CHECK(isPrime(143) == false);  // 11 * 13
    CHECK(isPrime(169) == false);  // 13 * 13
    CHECK(isPrime(200) == false);
}

TEST_CASE("testing even numbers greater than 2") {
    CHECK(isPrime(4) == false);
    CHECK(isPrime(50) == false);
    CHECK(isPrime(100) == false);
    CHECK(isPrime(1000) == false);
}
