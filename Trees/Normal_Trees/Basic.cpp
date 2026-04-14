#include<iostream>
#include<vector>
using namespace std;


// Node structure for tree
class Node {
    public :
    int data ;
    vector<Node* > children;

    Node(int x) {
        data = x;
    }
};

// Function to add a child to a node
void addChild(Node* parent , Node* child) {
    parent->children.push_back(child);
}

// Function to print children of each node
void printParents(Node* node , Node* parent) {
    if (parent == nullptr)
        cout << node->data << " -> NULL" << endl;
    else
        cout << node->data << " -> " << parent->data << endl;
    for (auto child : node->children) {
        printParents(child , node);
    }
}

// Function to print children of each node
void printChildren(Node* node) {
    cout << node->data << " -> ";
    for (auto child : node->children) 
        cout<< child->data << " ";
    cout << endl;

    for (auto child : node->children)
        printChildren(child);
}

// function to print leaf nodes
void printLeafNodes(Node* node) {
    if (node -> children.empty()) {
        cout << node->data << " ";
        return ;
    }
    for (auto child : node->children) 
    printLeafNodes(child);
}

// Function to print degree of each node
void printDegree(Node* node , Node* parent) {
    int degree = node->children.size();
    if (parent != nullptr)
        degree++;
    cout << node->data << " -> " << degree << endl;

    for (auto child : node->children)
        printDegree(child, node);
}

int main() {
    // Creating nodes
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    // Constructing tree
    addChild(root, n2);
    addChild(root, n3);
    addChild(n2, n4);
    addChild(n2, n5);

    cout << "Parents of each node:" << endl;
    printParents(root, nullptr);

    cout << "Children of each node:" << endl;
    printChildren(root);

    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Degrees of nodes:" << endl;
    printDegree(root, nullptr);

    return 0;
}