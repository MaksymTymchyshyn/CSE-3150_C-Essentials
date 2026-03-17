#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ComplexArray.h"

TEST_CASE("size-zero array") {
    ComplexArray arr(0);
    CHECK(arr.size() == 0);
}

TEST_CASE("store and retrieve values") {
    ComplexArray arr(3);
    arr[0] = ComplexNumber(1.0, 2.0);
    arr[1] = ComplexNumber(-3.0, 0.0);
    arr[2] = ComplexNumber(0.0, -4.5);

    CHECK(arr[0] == ComplexNumber(1.0, 2.0));
    CHECK(arr[1] == ComplexNumber(-3.0, 0.0));
    CHECK(arr[2] == ComplexNumber(0.0, -4.5));
    CHECK(arr.size() == 3);
}

TEST_CASE("move constructor transfers data") {
    ComplexArray src(2);
    src[0] = ComplexNumber(1.0, 1.0);
    src[1] = ComplexNumber(2.0, 2.0);

    ComplexArray dst(std::move(src));

    CHECK(dst.size() == 2);
    CHECK(dst[0] == ComplexNumber(1.0, 1.0));
    CHECK(dst[1] == ComplexNumber(2.0, 2.0));
    CHECK(src.size() == 0); // source should be empty
}

TEST_CASE("move assignment transfers data") {
    ComplexArray src(2);
    src[0] = ComplexNumber(5.0, -1.0);
    src[1] = ComplexNumber(0.0,  3.0);

    ComplexArray dst(0);
    dst = std::move(src);

    CHECK(dst.size() == 2);
    CHECK(dst[0] == ComplexNumber(5.0, -1.0));
    CHECK(dst[1] == ComplexNumber(0.0,  3.0));
    CHECK(src.size() == 0);
}

TEST_CASE("self move-assignment doesn't crash") {
    ComplexArray arr(1);
    arr[0] = ComplexNumber(7.0, 8.0);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-move"
    arr = std::move(arr);
#pragma GCC diagnostic pop
    // just checking it doesn't crash or corrupt memory
}

TEST_CASE("out-of-range access throws") {
    ComplexArray arr(2);
    CHECK_THROWS_AS(arr[-1], std::out_of_range);
    CHECK_THROWS_AS(arr[2],  std::out_of_range);
}

TEST_CASE("move from empty array") {
    ComplexArray src(0);
    ComplexArray dst(std::move(src));
    CHECK(dst.size() == 0);
    CHECK(src.size() == 0);
}

TEST_CASE("move assignment overwrites existing data") {
    ComplexArray dst(3);
    dst[0] = ComplexNumber(9.0, 9.0);

    ComplexArray src(1);
    src[0] = ComplexNumber(1.0, 0.0);

    dst = std::move(src);

    CHECK(dst.size() == 1);
    CHECK(dst[0] == ComplexNumber(1.0, 0.0));
}
