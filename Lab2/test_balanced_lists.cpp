#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "balanced_lists.h"
#include <algorithm>
#include <set>

TEST_CASE("generateSequence creates correct sequence") {
    SUBCASE("n = 3") {
        std::vector<int> seq = generateSequence(3);
        REQUIRE(seq.size() == 6);
        
        // Count ones and negative ones
        int countOnes = std::count(seq.begin(), seq.end(), 1);
        int countNegOnes = std::count(seq.begin(), seq.end(), -1);
        
        CHECK(countOnes == 3);
        CHECK(countNegOnes == 3);
    }
    
    SUBCASE("n = 5") {
        std::vector<int> seq = generateSequence(5);
        REQUIRE(seq.size() == 10);
        
        int countOnes = std::count(seq.begin(), seq.end(), 1);
        int countNegOnes = std::count(seq.begin(), seq.end(), -1);
        
        CHECK(countOnes == 5);
        CHECK(countNegOnes == 5);
    }
}

TEST_CASE("hasNonNegativePrefixSums works correctly") {
    SUBCASE("Simple well-balanced sequence: ()") {
        std::vector<int> seq = {1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
    
    SUBCASE("Well-balanced sequence: ()()") {
        std::vector<int> seq = {1, -1, 1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
    
    SUBCASE("Well-balanced sequence: ((()))") {
        std::vector<int> seq = {1, 1, 1, -1, -1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
    
    SUBCASE("Not well-balanced: starts with -1") {
        std::vector<int> seq = {-1, 1, 1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == false);
    }
    
    SUBCASE("Not well-balanced: negative prefix sum in middle") {
        std::vector<int> seq = {1, -1, -1, 1};
        CHECK(hasNonNegativePrefixSums(seq) == false);
    }
    
    SUBCASE("Edge case: empty sequence") {
        std::vector<int> seq = {};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
}

TEST_CASE("fisherYatesShuffle produces valid permutations") {
    initializeRandom();
    
    SUBCASE("Preserves all elements") {
        std::vector<int> original = {1, 1, 1, -1, -1, -1};
        std::vector<int> shuffled = original;
        
        fisherYatesShuffle(shuffled);
        
        // Sort both to compare
        std::vector<int> sortedOriginal = original;
        std::vector<int> sortedShuffled = shuffled;
        std::sort(sortedOriginal.begin(), sortedOriginal.end());
        std::sort(sortedShuffled.begin(), sortedShuffled.end());
        
        CHECK(sortedOriginal == sortedShuffled);
    }
    
    SUBCASE("Produces different orderings (probabilistic test)") {
        std::vector<int> original = {1, 1, 1, -1, -1, -1};
        std::set<std::vector<int>> uniqueShuffles;
        
        // Try 100 shuffles
        for (int i = 0; i < 100; i++) {
            std::vector<int> shuffled = original;
            fisherYatesShuffle(shuffled);
            uniqueShuffles.insert(shuffled);
        }
        
        // Should get at least a few different permutations out of 100 tries
        // (There are C(6,3) = 20 total permutations)
        CHECK(uniqueShuffles.size() > 5);
    }
    
    SUBCASE("Handles single element") {
        std::vector<int> seq = {42};
        fisherYatesShuffle(seq);
        CHECK(seq[0] == 42);
    }
    
    SUBCASE("Handles two elements") {
        std::vector<int> seq = {1, -1};
        std::vector<int> original = seq;
        
        fisherYatesShuffle(seq);
        
        // Should still be a valid permutation
        std::sort(seq.begin(), seq.end());
        std::sort(original.begin(), original.end());
        CHECK(seq == original);
    }
}

TEST_CASE("runExperiment returns valid ratio") {
    initializeRandom();
    
    SUBCASE("Returns ratio between 0 and 1") {
        double ratio = runExperiment(3, 100);
        CHECK(ratio >= 0.0);
        CHECK(ratio <= 1.0);
    }
    
    SUBCASE("Returns reasonable ratio for n=3") {
        // For n=3, theoretical ratio is C_3 / C(6,3) = 5/20 = 0.25
        double ratio = runExperiment(3, 1000);
        // With 1000 trials, should be reasonably close to 0.25
        // Using a generous range for probabilistic test
        CHECK(ratio > 0.15);
        CHECK(ratio < 0.35);
    }
    
    SUBCASE("Returns reasonable ratio for n=5") {
        // For n=5, theoretical ratio is C_5 / C(10,5) = 42/252 ≈ 0.1667
        double ratio = runExperiment(5, 1000);
        // Using a generous range for probabilistic test
        CHECK(ratio > 0.10);
        CHECK(ratio < 0.25);
    }
}

TEST_CASE("Specific well-balanced examples from assignment") {
    SUBCASE("()") {
        std::vector<int> seq = {1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
    
    SUBCASE("()()") {
        std::vector<int> seq = {1, -1, 1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
    
    SUBCASE("(((())))") {
        std::vector<int> seq = {1, 1, 1, 1, -1, -1, -1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
    
    SUBCASE("( () ((())) )") {
        // ( () ((())) )
        // 1, 1, -1, 1, 1, 1, -1, -1, -1, -1
        std::vector<int> seq = {1, 1, -1, 1, 1, 1, -1, -1, -1, -1};
        CHECK(hasNonNegativePrefixSums(seq) == true);
    }
}

TEST_CASE("Example from additional notes") {
    SUBCASE("-1, +1, +1, -1 is not well-balanced") {
        std::vector<int> seq = {-1, 1, 1, -1};
        // Prefix sums: 0, -1, 0, 1, 0
        // Has negative prefix sum, so not well-balanced
        CHECK(hasNonNegativePrefixSums(seq) == false);
    }
}
