#include "balanced_lists.h"
#include <iostream>
#include <iomanip>

int main() {
    // Initialize random number generator
    initializeRandom();
    
    std::cout << "Lab Week 2: Well-Balanced Lists Experiment" << std::endl;
    std::cout << "===========================================" << std::endl << std::endl;
    
    // Test with different values of n
    std::vector<int> nValues = {3, 5, 10, 15};
    int numTrials = 10000;  // Run 10,000 trials for each n
    
    std::cout << "Running " << numTrials << " trials for each value of n..." << std::endl << std::endl;
    
    for (int n : nValues) {
        std::cout << "n = " << n << " (sequence length = " << 2*n << "):" << std::endl;
        
        // Run experiment multiple times to show convergence
        std::cout << "  Incremental ratios:" << std::endl;
        std::vector<int> trialCounts = {1000, 2000, 5000, 10000};
        
        for (int trials : trialCounts) {
            double ratio = runExperiment(n, trials);
            std::cout << "    After " << std::setw(5) << trials << " trials: " 
                      << std::fixed << std::setprecision(6) << ratio << std::endl;
        }
        std::cout << std::endl;
    }
    
    // Final detailed run for n=10
    std::cout << "Detailed Analysis for n = 10:" << std::endl;
    std::cout << "==============================" << std::endl;
    
    int n = 10;
    int largeTrials = 50000;
    
    std::cout << "Running " << largeTrials << " trials..." << std::endl;
    double finalRatio = runExperiment(n, largeTrials);
    
    std::cout << std::endl;
    std::cout << "Results:" << std::endl;
    std::cout << "  Total trials: " << largeTrials << std::endl;
    std::cout << "  Well-balanced lists: " << static_cast<int>(finalRatio * largeTrials) << std::endl;
    std::cout << "  Ratio: " << std::fixed << std::setprecision(6) << finalRatio << std::endl;
    
    // Calculate the theoretical ratio (Catalan number ratio)
    // For n=10, the 10th Catalan number C_10 = 16796
    // The total number of permutations is C(20,10) = 184756
    // Theoretical ratio = 16796 / 184756 ≈ 0.090909
    std::cout << std::endl;
    std::cout << "Note: The theoretical ratio for n=10 is approximately 0.090909" << std::endl;
    std::cout << "      (This is the 10th Catalan number divided by C(20,10))" << std::endl;
    
    return 0;
}
