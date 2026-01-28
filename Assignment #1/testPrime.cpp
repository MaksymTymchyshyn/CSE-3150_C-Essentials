#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    int limit = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

TEST_CASE("testing edge cases") {
    CHECK(isPrime(-5) == false);
    CHECK(isPrime(0) == false);
    CHECK(isPrime(1) == false);
    CHECK(isPrime(2) == true);
}

TEST_CASE("testing prime numbers") {
    CHECK(isPrime(3) == true);
    CHECK(isPrime(5) == true);
    CHECK(isPrime(7) == true);
    CHECK(isPrime(11) == true);
    CHECK(isPrime(97) == true);
    CHECK(isPrime(101) == true);
}

TEST_CASE("testing composite numbers") {
    CHECK(isPrime(4) == false);
    CHECK(isPrime(9) == false);
    CHECK(isPrime(15) == false);
    CHECK(isPrime(100) == false);
    CHECK(isPrime(121) == false);
}
