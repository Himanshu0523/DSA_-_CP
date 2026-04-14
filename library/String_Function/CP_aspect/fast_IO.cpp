#include <iostream>
#include <string>

void fast_io_setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void competitive_string_operations() {
    fast_io_setup();
    
    // Fast string reading
    std::string s;
    std::cin >> s; // For single word
    std::getline(std::cin, s); // For entire line
    
    // Fast output
    std::cout << s << "\n"; // Use '\n' instead of endl for no flush
    
    // Character array for maximum speed (when needed)
    char buffer[1000000];
    std::cin.getline(buffer, 1000000);
}


#include <bits/stdc++.h>
using namespace std;

// Palindrome checking
bool is_palindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// String rotation
string rotate_string(const string& s, int k) {
    k = k % s.length();
    if (k == 0) return s;
    return s.substr(k) + s.substr(0, k);
}

// Character frequency counting
vector<int> char_frequency(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        if (isalpha(c)) {
            freq[tolower(c) - 'a']++;
        }
    }
    return freq;
}

// Anagram checking
bool are_anagrams(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;
    
    vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : s1) freq1[c - 'a']++;
    for (char c : s2) freq2[c - 'a']++;
    
    return freq1 == freq2;
}

// Longest common prefix of two strings
string longest_common_prefix(const string& s1, const string& s2) {
    int min_len = min(s1.length(), s2.length());
    int i = 0;
    while (i < min_len && s1[i] == s2[i]) {
        i++;
    }
    return s1.substr(0, i);
}