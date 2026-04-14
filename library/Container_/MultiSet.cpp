#include <iostream>
#include <set>        // Mandatory header
#include <functional> // For std::greater
#include <vector>

using namespace std;
// Basic declaration (ascending order)
// std::multiset<DataType> myMultiset;

// Custom sorting (e.g., descending)
// std::multiset<DataType, std::greater<DataType>> myMultiset;

// Multiset -
// Associative Container: Stores elements based on their value (key).
// Sorted Order: Elements are always sorted (ascending by default).
// Allows Duplicates: Unlike std::set, it can store multiple elements with the same value.
// Implementation: Typically a self-balancing Binary Search Tree (Red-Black Tree).

// Characteristics & complexity
// insertion - O(log n)  - maintain sorted order
// deletion  - O(log n)
// search(find , count) - O(log n)
// Access First/Last - O(1)   - begin() , rbegin()
// Size(empty , size) - O(1)

#include <iostream>
#include <initializer_list>
#include <functional>

template <typename Key, typename Compare = std::less<Key>>
class Multiset {
private:
    struct Node {
        Key key;
        Node* left;
        Node* right;
        int count;

        Node(const Key& k) : key(k), left(nullptr), right(nullptr), count(1) {}
    };

    Node* root;
    Compare comp;
    size_t size_;

    // Private helper functions
    Node* insert(Node* node, const Key& key) {
        if (!node) {
            size_++;
            return new Node(key);
        }

        if (comp(key, node->key)) {
            node->left = insert(node->left, key);
        } else if (comp(node->key, key)) {
            node->right = insert(node->right, key);
        } else {
            node->count++;
            size_++;
        }
        return node;
    }

    Node* find(Node* node, const Key& key) const {
        if (!node) return nullptr;

        if (comp(key, node->key)) {
            return find(node->left, key);
        } else if (comp(node->key, key)) {
            return find(node->right, key);
        } else {
            return node;
        }
    }

    Node* erase(Node* node, const Key& key, bool remove_all, size_t& removed_count) {
        if (!node) return nullptr;

        if (comp(key, node->key)) {
            node->left = erase(node->left, key, remove_all, removed_count);
        } else if (comp(node->key, key)) {
            node->right = erase(node->right, key, remove_all, removed_count);
        } else {
            if (remove_all || node->count == 1) {
                removed_count = node->count;
                size_ -= node->count;

                if (!node->left) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                } else if (!node->right) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->count = temp->count;
                size_t dummy;
                node->right = erase(node->right, temp->key, true, dummy);
            } else {
                node->count--;
                size_--;
                removed_count = 1;
            }
        }
        return node;
    }

    Node* minValueNode(Node* node) const {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    void inOrderTraversal(Node* node) const {
        if (node) {
            inOrderTraversal(node->left);
            for (int i = 0; i < node->count; i++) {
                std::cout << node->key << " ";
            }
            inOrderTraversal(node->right);
        }
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node* copyTree(Node* otherNode) {
        if (!otherNode) return nullptr;
        
        Node* newNode = new Node(otherNode->key);
        newNode->count = otherNode->count;
        newNode->left = copyTree(otherNode->left);
        newNode->right = copyTree(otherNode->right);
        size_ += otherNode->count;
        
        return newNode;
    }

public:
    // Constructors & Destructor
    Multiset() : root(nullptr), size_(0) {}
    
    Multiset(std::initializer_list<Key> init) : root(nullptr), size_(0) {
        for (const auto& key : init) {
            insert(key);
        }
    }
    
    Multiset(const Multiset& other) : root(nullptr), size_(0) {
        root = copyTree(other.root);
    }
    
    Multiset& operator=(const Multiset& other) {
        if (this != &other) {
            clear();
            root = copyTree(other.root);
        }
        return *this;
    }
    
    ~Multiset() {
        clear();
    }

    // Capacity
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    // Modifiers
    void insert(const Key& key) {
        root = insert(root, key);
    }
    
    size_t erase(const Key& key, bool remove_all = true) {
        size_t removed_count = 0;
        root = erase(root, key, remove_all, removed_count);
        return removed_count;
    }
    
    void clear() {
        clear(root);
        root = nullptr;
        size_ = 0;
    }

    // Lookup
    size_t count(const Key& key) const {
        Node* found = find(root, key);
        return found ? found->count : 0;
    }
    
    bool contains(const Key& key) const {
        return find(root, key) != nullptr;
    }

    // Traversal
    void print() const {
        std::cout << "[ ";
        inOrderTraversal(root);
        std::cout << "]" << std::endl;
    }
};

// Demo function
void demonstrateMultiset() {
    std::cout << "=== Custom Multiset Implementation ===\n" << std::endl;

    // 1. Creation & Initialization
    std::cout << "1. Creating multiset with initial values {5, 2, 8, 2, 5}:" << std::endl;
    Multiset<int> ms = {5, 2, 8, 2, 5};
    ms.print();
    std::cout << "Size: " << ms.size() << std::endl;

    // 2. Insertion
    std::cout << "\n2. Inserting values 3, 5, 1:" << std::endl;
    ms.insert(3);
    ms.insert(5);
    ms.insert(1);
    ms.print();
    std::cout << "Size: " << ms.size() << std::endl;

    // 3. Count and Contains
    std::cout << "\n3. Counting occurrences:" << std::endl;
    std::cout << "Count of 5: " << ms.count(5) << std::endl;
    std::cout << "Count of 2: " << ms.count(2) << std::endl;
    std::cout << "Count of 10: " << ms.count(10) << std::endl;
    std::cout << "Contains 8? " << (ms.contains(8) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 15? " << (ms.contains(15) ? "Yes" : "No") << std::endl;

    // 4. Erasure
    std::cout << "\n4. Erasing elements:" << std::endl;
    
    // Remove one occurrence of 5
    std::cout << "Removed " << ms.erase(5, false) << " instance of 5" << std::endl;
    ms.print();
    std::cout << "Count of 5 now: " << ms.count(5) << std::endl;
    
    // Remove all occurrences of 2
    std::cout << "Removed " << ms.erase(2, true) << " instances of 2" << std::endl;
    ms.print();

    // 5. Copy Constructor
    std::cout << "\n5. Testing copy constructor:" << std::endl;
    Multiset<int> ms_copy = ms;
    std::cout << "Original: ";
    ms.print();
    std::cout << "Copy: ";
    ms_copy.print();

    // 6. Assignment Operator
    std::cout << "\n6. Testing assignment operator:" << std::endl;
    Multiset<int> ms_assign;
    ms_assign = ms;
    std::cout << "Assigned: ";
    ms_assign.print();

    // 7. Clear
    std::cout << "\n7. Clearing the multiset:" << std::endl;
    ms.clear();
    std::cout << "After clear - Size: " << ms.size() << std::endl;
    std::cout << "Is empty? " << (ms.empty() ? "Yes" : "No") << std::endl;
    ms.print();

    // 8. Custom comparator (descending order)
    std::cout << "\n8. Multiset with descending order:" << std::endl;
    Multiset<int, std::greater<int>> ms_desc = {5, 2, 8, 2, 5};
    std::cout << "Descending order: ";
    ms_desc.print();
}

int main() {
    demonstrateMultiset();
    return 0;
}