#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "prefix_sums.h"

// Test cases for non_neg_prefix_sum

TEST_CASE("non_neg_prefix_sum: Example from lab - returns true") {
    int arr[] = {1, -1, 1, -1};
    CHECK(non_neg_prefix_sum(arr, 4) == true);
}

TEST_CASE("non_neg_prefix_sum: Example from lab - returns false") {
    int arr[] = {1, -1, -1, 1};
    CHECK(non_neg_prefix_sum(arr, 4) == false);
}

TEST_CASE("non_neg_prefix_sum: Empty array") {
    int arr[] = {};
    CHECK(non_neg_prefix_sum(arr, 0) == true);
}

TEST_CASE("non_neg_prefix_sum: Single element positive") {
    int arr[] = {1};
    CHECK(non_neg_prefix_sum(arr, 1) == true);
}

TEST_CASE("non_neg_prefix_sum: Single element negative") {
    int arr[] = {-1};
    CHECK(non_neg_prefix_sum(arr, 1) == false);
}

TEST_CASE("non_neg_prefix_sum: All positive") {
    int arr[] = {1, 1, 1, 1};
    CHECK(non_neg_prefix_sum(arr, 4) == true);
}

TEST_CASE("non_neg_prefix_sum: All negative") {
    int arr[] = {-1, -1, -1, -1};
    CHECK(non_neg_prefix_sum(arr, 4) == false);
}

TEST_CASE("non_neg_prefix_sum: Balanced but valid") {
    int arr[] = {1, 1, -1, -1};
    CHECK(non_neg_prefix_sum(arr, 4) == true);
}

TEST_CASE("non_neg_prefix_sum: Goes negative in middle") {
    int arr[] = {1, -1, -1, 1, 1};
    CHECK(non_neg_prefix_sum(arr, 5) == false);
}

TEST_CASE("non_neg_prefix_sum: Stays at zero") {
    int arr[] = {1, -1, 1, -1, 1, -1};
    CHECK(non_neg_prefix_sum(arr, 6) == true);
}

TEST_CASE("non_neg_prefix_sum: Large valid sequence") {
    int arr[] = {1, 1, 1, -1, -1, -1, 1, 1, -1};
    CHECK(non_neg_prefix_sum(arr, 9) == true);
}

TEST_CASE("non_neg_prefix_sum: Negative at end") {
    int arr[] = {1, 1, 1, -1, -1, -1, -1};
    CHECK(non_neg_prefix_sum(arr, 7) == false);
}

// Test cases for non_pos_prefix_sum

TEST_CASE("non_pos_prefix_sum: All negative") {
    int arr[] = {-1, -1, -1, -1};
    CHECK(non_pos_prefix_sum(arr, 4) == true);
}

TEST_CASE("non_pos_prefix_sum: Becomes positive") {
    int arr[] = {-1, 1, 1};
    CHECK(non_pos_prefix_sum(arr, 3) == false);
}

TEST_CASE("non_pos_prefix_sum: Empty array") {
    int arr[] = {};
    CHECK(non_pos_prefix_sum(arr, 0) == true);
}

TEST_CASE("non_pos_prefix_sum: Single element negative") {
    int arr[] = {-1};
    CHECK(non_pos_prefix_sum(arr, 1) == true);
}

TEST_CASE("non_pos_prefix_sum: Single element positive") {
    int arr[] = {1};
    CHECK(non_pos_prefix_sum(arr, 1) == false);
}

TEST_CASE("non_pos_prefix_sum: Stays at zero") {
    int arr[] = {-1, 1, -1, 1, -1, 1};
    CHECK(non_pos_prefix_sum(arr, 6) == true);
}

TEST_CASE("non_pos_prefix_sum: Balanced but invalid") {
    int arr[] = {-1, 1, 1, -1};
    CHECK(non_pos_prefix_sum(arr, 4) == false);
}

TEST_CASE("non_pos_prefix_sum: Goes positive in middle") {
    int arr[] = {-1, 1, 1, -1, -1};
    CHECK(non_pos_prefix_sum(arr, 5) == false);
}

TEST_CASE("non_pos_prefix_sum: All negative valid") {
    int arr[] = {-1, -1, -1, 1, 1, 1};
    CHECK(non_pos_prefix_sum(arr, 6) == true);
}

TEST_CASE("non_pos_prefix_sum: Immediate positive") {
    int arr[] = {1, -1};
    CHECK(non_pos_prefix_sum(arr, 2) == false);
}

// Combined edge cases

TEST_CASE("Edge case: Alternating starting with 1") {
    int arr[] = {1, -1, 1, -1, 1, -1, 1, -1};
    CHECK(non_neg_prefix_sum(arr, 8) == true);
    CHECK(non_pos_prefix_sum(arr, 8) == false);
}

TEST_CASE("Edge case: Alternating starting with -1") {
    int arr[] = {-1, 1, -1, 1, -1, 1, -1, 1};
    CHECK(non_neg_prefix_sum(arr, 8) == false);
    CHECK(non_pos_prefix_sum(arr, 8) == true);
}

TEST_CASE("Edge case: Long sequence staying non-negative") {
    int arr[] = {1, 1, 1, 1, -1, -1, -1, -1};
    CHECK(non_neg_prefix_sum(arr, 8) == true);
    CHECK(non_pos_prefix_sum(arr, 8) == false);
}
