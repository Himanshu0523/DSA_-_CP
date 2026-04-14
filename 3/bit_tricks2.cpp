//EXPERT BIT MANIPULATION CHEAT SHEET


#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "=== EXPERT BIT TRICKS ===\n\n";

    // 1. Basic Operations

    int n = 29; // 11101
    int i = 3;

    n |= (1 << i);  // Set ith bit
    n &= ~(1 << i); // Clear ith bit
    n ^= (1 << i);  // Toggle ith bit
    bool isSet = (n & (1 << i)); // Check ith bit
    int count = __builtin_popcount(n); // Count set bits
    bool isPower2 = (n & (n-1)) == 0; // Check power of 2
    int rightmost = n & -n; // Isolate rightmost set bit
    n &= (n-1); // Clear rightmost set bit

    // 2. Iterate Over Set Bits (Expert)
    n = 29; // 11101
    vector<int> positions;
    while(n) {
        int bit = n & -n;       // Rightmost set bit
        int pos = __builtin_ctz(bit); // Index
        positions.push_back(pos);
        n ^= bit;               // Remove rightmost set bit
    }
    cout << "Set bit positions: ";
    for(auto p: positions) cout << p << " ";
    cout << "\n";

    // 3. Subsets and Submasks (CP Gold)
    int size = 3; // Set size
    cout << "All subsets:\n";
    for(int mask=0; mask < (1<<size); mask++) {
        for(int j=0; j<size; j++)
            if(mask & (1<<j)) cout << j << " ";
        cout << "\n";
    }

    // Submasks enumeration
    int mask = 7; // 111
    cout << "Submasks:\n";
    for(int sub = mask; sub; sub = (sub-1) & mask)
        cout << sub << " ";
    cout << "\n";

    // 4. XOR Tricks (Interview)
    int a = 5, b = 9;
    a ^= b; b ^= a; a ^= b; // Swap without temp
    int xorPrefix[6] = {0,1,3,0,4,6}; // Example prefix XOR array
    int subarrayXOR = xorPrefix[5] ^ xorPrefix[2]; // XOR of subarray 3..5

    // 5. Gray Code (Expert/CP)
    cout << "3-bit Gray codes: ";
    for(int i=0; i<(1<<3); i++)
        cout << (i ^ (i>>1)) << " ";
    cout << "\n";

    // 6. Counting / Checking Bits
    n = 20;
    cout << "Trailing zeros: " << __builtin_ctz(n) << "\n";
    cout << "Leading zeros: " << __builtin_clz(n) << "\n";
    cout << "Population count: " << __builtin_popcount(n) << "\n";

    // 7. Power of 2, Even/Odd & Shifts
    cout << "Is n even? " << ((n & 1) == 0) << "\n";
    cout << "Multiply by 2^k: " << (n << 2) << "\n"; // multiply by 4
    cout << "Divide by 2^k: " << (n >> 2) << "\n";   // divide by 4

    // 8. Advanced Tricks (CP & Expert)
    // Turn on rightmost 0 bit
    cout << "Turn on rightmost 0: " << (n | (n+1)) << "\n";
    // Isolate lowest set bit: n & -n
    // Count submasks of mask using bits: 1<<popcount(mask)

    // Swap nibbles/bytes
    auto swapNibbles = [](int x) {
        return ((x & 0xF0)>>4) | ((x & 0x0F)<<4);
    };
    cout << "Swap nibbles of 0xAB: " << hex << swapNibbles(0xAB) << "\n";

    // Bitmask DP pattern (TSP, subset sum, etc.)
    int dp[1<<3] = {0};
    dp[0] = 0;
    for(int mask=1; mask<(1<<3); mask++) {
        for(int sub = mask; sub; sub = (sub-1)&mask) {
            // dp[mask] update based on sub
        }
    }

    return 0;
}
