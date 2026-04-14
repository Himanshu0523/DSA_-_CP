#include <vector>
#include <string>
#include <algorithm>

struct Suffix {
    int index;
    std::string suffix;
};

std::vector<int> build_suffix_array(const std::string& text) {
    int n = text.length();
    std::vector<Suffix> suffixes(n);
    
    for (int i = 0; i < n; i++) {
        suffixes[i] = {i, text.substr(i)};
    }
    
    // Sort suffixes lexicographically
    std::sort(suffixes.begin(), suffixes.end(), 
        [](const Suffix& a, const Suffix& b) {
            return a.suffix < b.suffix;
        });
    
    std::vector<int> suffix_array(n);
    for (int i = 0; i < n; i++) {
        suffix_array[i] = suffixes[i].index;
    }
    
    return suffix_array;
}

std::vector<int> build_lcp_array(const std::string& text, const std::vector<int>& suffix_array) {
    int n = text.length();
    std::vector<int> lcp(n, 0);
    std::vector<int> rank(n, 0);
    
    // Build rank array
    for (int i = 0; i < n; i++) {
        rank[suffix_array[i]] = i;
    }
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        
        int j = suffix_array[rank[i] + 1];
        while (i + k < n && j + k < n && text[i + k] == text[j + k]) {
            k++;
        }
        
        lcp[rank[i]] = k;
        if (k > 0) k--;
    }
    
    return lcp;
}