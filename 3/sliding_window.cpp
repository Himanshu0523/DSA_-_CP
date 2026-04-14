#include<iostream>
#include<vector>
using namespace std;

// Sliding windows techniques
    //  A window (range or subarray/substring) that "slides" over the data expanding or shrinking as per condition.

    // used - working subarrays/substrings /contiguous elements 
    //        like sum , count , max, min, distinct , frequency - within range.
    //        previous window efficiently -


// type of Sliding Windows
    // fixed size window
    // Variablee-size window
    // Dynamic two-pointer window


// Core Pattern Technique
    // fixed size Window
    int maxSum(vector<int>& arr, int k) {
        int n = arr.size() , sum =0 , ans = 0;
        for(int i = 0; i<k; i++) {
            ans = sum;
            for (int i = 0; i < n; i++){
                sum += arr[i] - arr[i - k];
                ans = max(ans , sum);
            }
            return ans;
        }
    }

    


