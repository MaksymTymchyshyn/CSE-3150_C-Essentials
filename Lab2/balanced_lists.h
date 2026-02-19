#ifndef BALANCED_LISTS_H
#define BALANCED_LISTS_H

#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @brief Fisher-Yates algorithm to randomly shuffle a vector
 * @param list The vector to shuffle (modified in place)
 */
void fisherYatesShuffle(std::vector<int>& list);

/**
 * @brief Generate a vector of n ones followed by n negative ones
 * @param n The number of ones (and negative ones)
 * @return A vector of size 2n with n ones and n negative ones
 */
std::vector<int> generateSequence(int n);

/**
 * @brief Check if all prefix sums are non-negative
 * @param list The vector to check
 * @return true if all prefix sums are >= 0, false otherwise
 */
bool hasNonNegativePrefixSums(const std::vector<int>& list);

/**
 * @brief Run the experiment: generate random sequences and count well-balanced ones
 * @param n The parameter n (sequence size will be 2n)
 * @param numTrials The number of trials to run
 * @return The ratio of well-balanced lists to total lists
 */
double runExperiment(int n, int numTrials);

/**
 * @brief Initialize random number generator with current time
 */
void initializeRandom();

#endif // BALANCED_LISTS_H
