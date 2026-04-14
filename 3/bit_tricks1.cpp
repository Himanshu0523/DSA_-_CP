

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "=== BIT MANIPULATION CHEAT SHEET ===\n\n";

    // =================================
    // 1. Basic Bit Operations
    // =================================

    int n = 29; // 11101 in binary
    int i = 3;

    // Set ith bit
    n |= (1 << i); 


    // Clear ith bit
    n &= ~(1 << i);


    // Toggle ith bit
    n ^= (1 << i);


    // Check ith bit
    bool isSet = (n & (1 << i)) != 0;

    // Count set bits
    int count = __builtin_popcount(n); // 4

    // Rightmost set bit
    int rightmost = n & -n; // isolates lowest set bit

    // Clear rightmost set bit
    n &= (n-1);

    // Check if n is power of 2
    bool isPower2 = (n & (n-1)) == 0;

    cout << "Basic operations done.\n";

    // =================================
    // 2. Iterate Through Set Bits
    // =================================
    n = 29; // 11101
    vector<int> positions;

    // Method 1: simple loop
    for(int j = 0; n; j++) {
        if(n & 1) positions.push_back(j);
        n >>= 1;
    }
    // positions = [0,2,3,4]

    // Method 2: using Brian Kernighan's algorithm
    n = 29;
    positions.clear();
    while(n) {
        int bit = n & -n;
        int pos = __builtin_ctz(bit);
        positions.push_back(pos);
        n ^= bit;
    }

    cout << "Positions of set bits: ";
    for(int x : positions) cout << x << " ";
    cout << "\n";

    // =================================
    // 3. Subsets / Bitmasking
    // =================================

    int size = 3; // set size
    for(int mask = 0; mask < (1 << size); mask++) {
        cout << "Subset mask: " << mask << " -> ";
        for(int j = 0; j < size; j++) {
            if(mask & (1 << j)) cout << j << " ";
        }
        cout << "\n";
    }

    // Submasks
    int mask = 7; // 111
    cout << "Submasks of " << mask << ":\n";
    for(int sub = mask; sub; sub = (sub-1) & mask) {
        cout << sub << " ";
    }
    cout << "\n";

    // =================================
    // 4. XOR Tricks
    // =================================
    int a = 5, b = 9;
    // Swap without temp
    a ^= b;
    b ^= a;
    a ^= b;

    // =================================
    // 5. Gray Code
    // =================================
    cout << "Gray codes for 3 bits:\n";
    for(int i = 0; i < (1 << 3); i++) {
        int gray = i ^ (i >> 1);
        cout << gray << " ";
    }
    cout << "\n";

    // =================================
    // 6. Bit Manipulation Shortcuts
    // =================================
    n = 20;
    cout << "n even? " << ((n & 1) == 0) << "\n";
    cout << "Turn off rightmost 1: " << (n & (n-1)) << "\n";
    cout << "Turn on rightmost 0: " << (n | (n+1)) << "\n";
    cout << "Rightmost set bit: " << (n & -n) << "\n";

    return 0;
}
