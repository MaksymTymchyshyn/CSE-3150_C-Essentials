#include "prefix_sums.h"

bool non_neg_prefix_sum(const int arr[], int size) {
    int prefix_sum = 0;
    
    // Check if any prefix sum goes below 0
    for (int i = 0; i < size; i++) {
        prefix_sum += arr[i];
        if (prefix_sum < 0) {
            return false;
        }
    }
    
    return true;
}

bool non_pos_prefix_sum(const int arr[], int size) {
    int prefix_sum = 0;
    
    // Check if any prefix sum goes above 0
    for (int i = 0; i < size; i++) {
        prefix_sum += arr[i];
        if (prefix_sum > 0) {
            return false;
        }
    }
    
    return true;
}
