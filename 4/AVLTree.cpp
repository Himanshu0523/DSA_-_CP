// AVL Tree - self-balancing - BST(Binary Search Tree) 
    // Self-balancing Binary Search Tree (BST)
    // For every node:
        // Balanced Factor = height(left)  -  height(right)
        // -1  <= Balancing factor <=  +1

    //  AVL ?
        // Height = O(log n) -> ensures fast search , insert , delete
        // Restore balance using rotations after insert / delete.

        // Rotations (Rebalancing)
        //  Used to maintain balance in O(1) time.

        // Case            Conditions                  Fix
        // LL        Insert in L subtree of L child    Right Rotation
        // RR        Insert in R subtree of R          Left Rotation
        // LR        Insert in R subtree of L child    Left->Right Rotations
        // RL        Insert in L subtree of R child    Right->Left Rotations


        // Operations
            // Operation       Description                                       Time
            // Search          same as BST                                       O(log n)
            // Insert          Normal BST insert + rotations                     O(log n)
            // Delete          Normal BST delete + possible multiple rotations   O(log n)

        // Advantage 
            // Always balanced 
            // Faster lookups than Red -black Tree
            // Sorted Traversal

        // Disadvantage
            // More complex
            // Higher overhead
            // Less used than Red-black Trees in Libraries.


        // Applications -
            //  Searches Dominate 
            //  Databases , memory indexing , or real-time systems needing predictable time.
            //  Self-balancing BSTs.




#include<bits/stdc++.h>
using namespace std;

// AVL Tree node
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};


// utility function to get the height of the tree
int height(Node *N) {
    if (N == nullptr)return 0;
    return N->height;
}

// Utility functions to right rotate subtree rooted with y
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotations
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y -> left), height(y->right));
    x->height = 1 + max(height(x -> left), height(x->right));

    // return new root
    return x;
}


// Utility functions to left rotate subtree rooted with x
Node *leftRotate(Node *x) {
    Node *y = x -> right;
    Node *T2 = y -> left;

    // Perform rotations
    y -> left = x;
    x -> right = T2;

    //Update heights
    x -> height = 1 + max(height(x->left) , height(x -> right));
    y -> height = 1 + max(height(y -> left), height(y->right));

    // return new root
    return y;
}