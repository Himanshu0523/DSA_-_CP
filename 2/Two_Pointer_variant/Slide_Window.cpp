#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Sliding window Technique 
    // Contiguous subarray or substring by maintaining "WINDOW" slideover the data . avoid calcutating results - overlapping windows .

    // subarray or Substring
    // keyword - "Longest","shortest","contains","maximum","minimum"
    // contraints - 

    // Two Main Types
        // Fixed-Length Wimdow - window size k - predetermined
        // Variable-Length Window - window expands & shrinks find - optimal size based condition.

// Fixed-Size Sliding Window
    // Maximum sum of subarray of size k
    int maXSumSubarray(const vector<int>& nums , int k){
        if (nums.size() < k) return -1;

        int windowsum = 0;
        // Calculate inital window sum
        for(int i = 0; i < k; i++){
            windowsum += nums[i];
        }

        int maxsum = windowsum;
        // Slide the window
        for(int i = k; i< nums.size(); i++){
            windowsum = windowsum + nums[i] - nums[i - k];
            maxsum = max(maxsum , windowsum);
        }
        return maxsum;
    }



// Count occurrence of anagram of pattern in string
int countAnagrams(const string& s, const string& p){
    if (s.length() < p.length()) return 0;

    vector<int> pCount(26, 0), sCount(26, 0);
    int count = 0;

    //Initialize frequency arrays
    for(int i = 0; i< p.length(); i++){
        pCount[p[i] - 'a']++;
        sCount[s[i] - 'a']++;
    }

    if(pCount == sCount) count++;

    //Slide the window
    for(int i = p.length(); i < s.length(); i++){
        sCount[s[i] - 'a']++;
        sCount[s[i - p.length()] - 'a']--;

        if(pCount == sCount) count++;
    }
    return count;
}




int main() {

    return 0;
}