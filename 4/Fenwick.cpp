#include<iostream>
using namespace std;



// Binary Indexed Tree or Fenwick Tree 

    // BIT (Binary Indexed Tree)
        // used prefix queries (sum , XOR, etc.) and updates in O(log n)
        // Spaces - O(n) | Build  - O(n log n)

    // Core Concepts
        // Parent :  index - (index & -index)
        // Next child : index + (index & -index)
        // Based on binary representation - each node covers power-of-2 range.

    // Operations
        // gettSum(x):
            // Repeatedly add BITree[index] and move to parent.
            // index -= index & - index

        // update(x, val):
            // Add val - all ranges containing arr[x]
            // index += index & - index

    // Notes 
        // Ranges sum = getSum(R) - getSum(L -1)
        
        



// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[] , int index) {
    int sum = 0;
    index = index + 1;

    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}


// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void updateBIT(int BITree[] , int n , int index, int val) {
    index = index + 1;
    while (index <= n) {
        BITree[index] += val;
        index += index & (- index);
    }
}


// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[] , int n) {
    int *BITree = new int[n + 1];
    for (int i = 1; i <= n; i++) 
        BITree[i] = 0;

    for (int i = 0; i < n; i++) 
        updateBIT(BITree , n, i, arr[i]);

    return BITree;
}


int main(){
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq) / sizeof(freq[0]);
    int *BITree = constructBITree(freq , n);
    cout << "Sum  of elements in arr[0...5] is" << getSum(BITree , 5);

    // Let use test the update operations
    freq[3] += 6;
    updateBIT(BITree , n, 3, 6);
    // Update BIT for above change in arr[]
    cout  << "\n Sum of elements in arr[0...5] after update is " << getSum(BITree , 5);

    return 0;
}

// Time Complexity - O(N logN)
// Auxiliary Space - O(N)

// can extend the Binary Indexed Tree - sum of a range in O(LogN) time 
    // rangeSum(l , r) = getSum(r) - getSum(l -1);