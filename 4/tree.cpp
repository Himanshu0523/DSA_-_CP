#include<iostream>
#include<vector>
using namespace std;


class Node {
    public:
        int data;
        vector<Node* > children;
        Node(int x) {
            data = x;
        }
};

void addChild(Node* parent , Node* child) {
    parent->children.push_back(child);
}

void printParents(Node* node , Node* parent) {
    if(parent == nullptr)
        cout << node->data << "  -> NULL "<< endl;
    else 
        cout << node->data << " -> "<< parent->data << endl;

    for (auto child : node->children)
        printParents(child , node);
}

void printChildren(Node* node) {
    cout << node->data << " -> ";
    for (auto child : node->children)
        cout << child->data << " ";
    cout << endl;

    for(auto child : node->children) 
        printChildren(child);
}


void printLeafNodes(Node* node) {
    if (node->children.empty()) {
        cout << node->data << " ";
        return ;
    }
    for (auto child : node->children)
        printLeafNodes(child);
}

void printDegrees(Node* node , Node* parent) {
    int degree = node->children.size();
    if(parent != nullptr)
        degree++;
    cout << node->data << " -> "<< degree << endl;

    for (auto child : node->children)
        printDegrees(child , node);
}

int main() {
    // creating nodes
    Node* root = new Node(1);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    // Constructing tree
    addChild(root , n2);
    addChild(root , n3);
    addChild(n2 , n4);
    addChild(n2 , n5);

    cout << " Parents of each node: " << endl;
    printParents(root , nullptr);

    cout << " Children of each node:" << endl;
    printChildren(root);

    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Degrees of nodes: " << endl;
    printDegrees(root , nullptr);

    return 0;
}