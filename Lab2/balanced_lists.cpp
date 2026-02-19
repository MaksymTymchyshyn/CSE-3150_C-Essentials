#include "balanced_lists.h"
#include <algorithm>

void initializeRandom() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void fisherYatesShuffle(std::vector<int>& list) {
    int n = list.size();
    for (int i = n - 1; i > 0; i--) {
        // Generate random index from 0 to i (inclusive)
        int j = std::rand() % (i + 1);
        // Swap elements at i and j
        std::swap(list[i], list[j]);
    }
}

std::vector<int> generateSequence(int n) {
    std::vector<int> sequence;
    sequence.reserve(2 * n);
    
    // Add n ones
    for (int i = 0; i < n; i++) {
        sequence.push_back(1);
    }
    
    // Add n negative ones
    for (int i = 0; i < n; i++) {
        sequence.push_back(-1);
    }
    
    return sequence;
}

bool hasNonNegativePrefixSums(const std::vector<int>& list) {
    int prefixSum = 0;
    
    for (int value : list) {
        prefixSum += value;
        if (prefixSum < 0) {
            return false;  // Found a negative prefix sum
        }
    }
    
    return true;  // All prefix sums are non-negative
}

double runExperiment(int n, int numTrials) {
    int wellBalancedCount = 0;
    
    for (int trial = 0; trial < numTrials; trial++) {
        // Step 1: Generate sequence of n ones and n negative ones
        std::vector<int> sequence = generateSequence(n);
        
        // Step 2: Shuffle using Fisher-Yates
        fisherYatesShuffle(sequence);
        
        // Step 3 & 4: Check if all prefix sums are non-negative
        if (hasNonNegativePrefixSums(sequence)) {
            wellBalancedCount++;
        }
    }
    
    // Return the proportion
    return static_cast<double>(wellBalancedCount) / numTrials;
}
