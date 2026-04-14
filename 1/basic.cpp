#include<bits/stdc++.h>
using namespace std;



int main() {
vector<vector<int>> nums(10, vector<int>(10, 0));
    int n = nums.size();
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (i == j || i == k || j == k) continue;
            // Process triangle
        }
    }
}

// This considers 6 different permutations of the same 3 points:
// (i,j,k), (i,k,j), (j,i,k), (j,k,i), (k,i,j), (k,j,i)

// Optimized approach:
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            // Process triangle
        }
    }
}

// Performance Improvement
// Original: O(n³) with many duplicates → 6× more iterations

// Optimized: O(n³/6) → much faster


// Combinations: ⁿC₃ = n!/(3!(n-3)!) → This is what we want

// Permutations: ⁿP₃ = n!/(n-3)! → This is what your original code does

    return 0;
}