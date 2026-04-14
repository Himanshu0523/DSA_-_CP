#include <unordered_map>
#include <memory>

class TrieNode {
public:
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
    bool is_end_of_word;
    
    TrieNode() : is_end_of_word(false) {}
};

class Trie {
private:
    std::shared_ptr<TrieNode> root;
    
public:
    Trie() : root(std::make_shared<TrieNode>()) {}
    
    void insert(const std::string& word) {
        auto node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = std::make_shared<TrieNode>();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }
    
    bool search(const std::string& word) {
        auto node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->is_end_of_word;
    }
    
    bool startsWith(const std::string& prefix) {
        auto node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};