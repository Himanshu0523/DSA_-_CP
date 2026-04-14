#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int a)
    {
        data = a;
        left = right = nullptr;
    }
};

// functions to find index of value in arr[start... end]
// The function assumes that value is present in in[]
int search(vector<int> &arr, int start, int end, int value)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

// Recursive function to construct binary tree of size n from Inorder Traversal in[] and PostOrder traversal post[]. Initial values of inStrt and inEnd should be 0 and n - 1.
Node *buildUtil(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int &pIndex)
{
    // if inStart is greater than inEnd return nullptr
    if (inStart > inEnd)
        return nullptr;

    // Pick current node from PostOrder traversal using PostIndex and decrement psotIndex
    Node *node = new Node(postorder[pIndex]);
    pIndex--;

    // If this node has no children then return
    if (inStart == inEnd)
        return node;

    // Else find the index of this node is InOrder treversal
    int iIndex = search(inorder, inStart, inEnd, node->data);

    // Using index in Inorder Traversal , construct left end
    // Right subtrees
    node->right == buildUtil(inorder, postorder, iIndex + 1, inEnd, pIndex);
    node->left == buildUtil(inorder, postorder, iIndex - 1, inEnd, pIndex);

    return node;
}

// This function mainly inititalizes index of root and calls buildUtil()
    // Node *buildTree(vector<int> &inorder , vector<int> &postOrder) {
    //     int n = inorder.size();
    //     int pindex = n - 1;
    //     return buildUtil();
    // }

// construct a Binary Tree from postOrder and Inorder

// [ Naive Approach ] Search current element every time - O(n ^ 2) Time and O(n) space
//
