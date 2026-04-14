// kmp 
#include <vector> 
#include <iostream> 
#include <string>
#include <cmath>


using namespace std;
std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

std::vector<int> KMP_search(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0) return result;
    
    std::vector<int> lps = computeLPS(pattern);
    int i = 0; // text index
    int j = 0; // pattern index
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}



// Rabin-Karp Algorithm
std::vector<int> rabin_karp_search(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    int n = text.length();
    int m = pattern.length();
    if (m == 0 || n < m) return result;
    
    const int prime = 101;
    const int d = 256; // Number of characters in input alphabet
    
    long long pattern_hash = 0;
    long long text_hash = 0;
    long long h = 1;
    
    // Calculate h = d^(m-1) % prime
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % prime;
    }
    
    // Calculate initial hash values
    for (int i = 0; i < m; i++) {
        pattern_hash = (d * pattern_hash + pattern[i]) % prime;
        text_hash = (d * text_hash + text[i]) % prime;
    }
    
    for (int i = 0; i <= n - m; i++) {
        // Check hash values first
        if (pattern_hash == text_hash) {
            // If hash matches, verify character by character
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        
        // Calculate hash for next window
        if (i < n - m) {
            text_hash = (d * (text_hash - text[i] * h) + text[i + m]) % prime;
            if (text_hash < 0) {
                text_hash += prime;
            }
        }
    }
    return result;
}


int main(int argc, char const *argv[])
{
    /* code */

    cout << "Hello, World!" << endl;
    return 0;
}
