#ifndef PREFIX_SUMS_H
#define PREFIX_SUMS_H

/**
 * Checks if all prefix sums of an array of +1 and -1 values never go below zero.
 * 
 * @param arr The input array containing only +1 and -1 values
 * @param size The size of the array
 * @return true if all prefix sums are >= 0, false otherwise
 */
bool non_neg_prefix_sum(const int arr[], int size);

/**
 * Checks if all prefix sums of an array of +1 and -1 values never go above zero.
 * 
 * @param arr The input array containing only +1 and -1 values
 * @param size The size of the array
 * @return true if all prefix sums are <= 0, false otherwise
 */
bool non_pos_prefix_sum(const int arr[], int size);

#endif // PREFIX_SUMS_H
