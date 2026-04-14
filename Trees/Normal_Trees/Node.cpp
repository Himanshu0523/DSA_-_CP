#include <vector>
#include <stack>
#include<queue>
#include <iostream>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

void inOrder(Node *node, vector<int> &res)
{
    if (node == nullptr)
        return;
    inOrder(node->left, res);
    res.push_back(node->data);
    inOrder(node->right, res);
}

vector<int> inOrder_(Node *root)
{
    vector<int> ans;
    stack<Node *> s;
    Node *curr = root;

    while (curr != nullptr || s.empty() == false)
    {
        // reach the left most Node of the curr Node
        while (curr != nullptr)
        {
            // Place pointer to a tree node on the stack before traversing the node's left subtree
            s.push(curr);
            curr = curr->left;
        }
        // Current must be NULL at this points
        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        // we have visited the node and its left subtree. Now , it's right subtree's turn
        curr = curr->right;
    }
    return ans;
}

int search(vector<int> &inorder, int value, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node *buildTreeRecur(vector<int> &inorder, vector<int> &preorder, int &preIndex, int left, int right)
{
    // for empty inorder array , return null
    if (left > right)
        return nullptr;
    int rootVal = preorder[preIndex];
    preIndex++;

    Node *root = new Node(rootVal);
    int index = search(inorder, rootVal, left, right);
    // Recursively create the left ans right subtree
    root->left = buildTreeRecur(inorder, preorder, preIndex, left, index - 1);
    root->right = buildTreeRecur(inorder, preorder, preIndex, index + 1, right);

    return root;
}

// Recursive fuction to build the binary tree
Node *buildTreeRecur(unordered_map<int, int> &mp , vector<int> &preorder , int &preIndex , int left , int right) {
    // for empty inorder array , return null
    if (left > right)
        return nullptr;

    int rootval = preorder[preIndex];
    preIndex++;

    Node *root = new Node(rootval);
    int index = mp[rootval];

    // recursively create the left and right subtree.
    root->left = buildTreeRecur(mp , preorder , preIndex , left , index - 1);
    root ->right = buildTreeRecur(mp, preorder , preIndex , index + 1, right);

    return root;
}

// Function to construct tree from its inorder ans preorder traversals
Node *buildTree(vector<int> &inorder , vector<int> &preorder) {
    int preIndex = 0;
    Node *root = buildTreeRecur(inorder , preorder , preIndex , 0 , preorder.size() - 1);

    // Hash map that stores index of a root element in inorede array
    // unordered_map<int , int> mp;
    // for(int i = 0; i < inorder.size() ; i++) {
    //     mp[inorder[i]] = i;
    // }
    // int preIndex = 0;
    // Node *root = buildTreeRecur(mp , preorder , preIndex , 0 , inorder.size() - 1);

    return root;
}

int getHeight(Node* root , int h) {
    if (root == nullptr)return h - 1;
    return max(getHeight(root -> left , h + 1) , getHeight(root-> right, h + 1));
}

void levelOrder(Node* root) {
    queue<pair <Node* , int>> q;
    q.push({root , 0});

    int lastlevel = 0;
    int height = getHeight(root , 0);
    // printing the level order of tree

    while (!q.empty()) {
        auto  top = q.front()  ;
        q.pop();
        Node* node = top.first;
        int lvl = top.second;

        if(lvl > lastlevel) {
            cout << "\n" ;
            lastlevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;
        if (node -> data != -1) cout << node->data << " ";
        // printing null node
        else cout<< "N";
        // Null node has no children
        if (node->data == -1) continue;
        if (node->left == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->left , lvl + 1});
        if(node->right == nullptr) q.push({new Node(-1) , lvl + 2});
        else q.push({node->right , lvl + 1});
    }

}
int main()
{
    // Intitalize and allocate for tree nodes
    Node *firstNode = new Node(1);
    Node *secondNode = new Node(2);
    Node *thirdNode = new Node(3);
    Node *fourthNode = new Node(4);
    Node *fiveNode = new Node(5);

    // Connect binary tree nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;


    // approach 1 using pre-order traversal - O(n^2) Time ans O(h) space
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);


    // Using Pre-order Traversal and hash map = o(n) time ans o(n) space



    levelOrder(root);
    return 0;
}