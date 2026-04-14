#include<bits/stdc++.h>
using namespace std;

// Fixed size Window
    // Maximum Sum Subarray of Size K
        int maxSumSubarray(vector<int> &arr, int k) {
            int sum = 0 , maxi = 0, i = 0;
            for(; i< k; i++)sum += arr[i];
            maxi = max(sum , maxi);
            for(int j = k; j < arr.size(); j++) {
                sum -= arr[j - k] + arr[j];
                maxi = max(maxi , sum);
            }
            return maxi;
        }


    vector<int> firstNegative(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i =0; i<arr.size(); i++) {
            if(arr[i] < 0) dq.push_back(i);
            
            if(i >= k - 1) {
                if (!dq.empty()) ans.push_back(arr[dq.front()]);
                else ans.push_back(0);

                if(!dq.empty() && dq.front() <= i - k + 1) 
                    dq.pop_front();
            }
        }
        return ans;
    }

    // Maximum element in evert Windows