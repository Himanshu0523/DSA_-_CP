
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// 1. Opposite-End / Two-End Pointers

//     Place one pointer at the start, one at the end. Move inward based on conditions.

//_____________________________Application______________________________________

 
// Container with most water 

    // Problem: Given an array of heights, find two lines that form a container with the maximum area.
    // Concept: Use two pointers from the ends, move the shorter line inward.

    int maxArea(vector<int> &height) {
        int right = height.size() - 1 , left = 0;
        int max_area = 0;

        while(left < right){
            int area = min(height[left] , height[right]) * (right - left); // height * weight
            max_area = max(max_area , area);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }

// Trapping Rain Water 

    // Problem: Find how much water can be trapped between bars.
    // Concept: Use two pointers from ends, track max heights from left and right.


    int trap(vector<int>& height) {
        int left = 0 , right = height.size() - 1;
        int left_max = 0, right_max = 0, water = 0;

        while (left < right){
            int h_m = 0 , h_ = 0;
            if(height[left] < height[right]) {
                height[left] >= left_max ? left_max = height[left] : water += left_max - height[left];
                left++;
            }
            else {
                height[right] >= right_max ? right_max = height[right] : right_max += right_max - height[right];
                right--;
            }
        }
        return water;
    }


// 3Sum / 3Sum Closest

    // Problem: Find triplets that sum to zero (or closest to target) in a sorted array.
    // Concept: Fix one element, use opposite-end pointers for the other two.

    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;

        for(int i = 0; i< nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int left = i + 1, right = nums.size() - 1 ;
            while (left < right) {
                int sum = nums[i] + nums[left] +nums[right];
                if(sum == 0){
                    res.push_back({nums[i] , nums[left], nums[right]});
                    left++; right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                }else if(sum < 0) left++;
                else right--;
            }
        }
        return res;
    }



// Maximum Sum of Pairs ≤ Target

    // Problem: Given a sorted array, find two elements whose sum is closest to but ≤ target.
    // Concept: Two-end pointers with optimization for closest sum.

    int maxPairSum(vector<int>& arr , int target) {
        int left = 0 , right = arr.size() - 1;
        int maxSum = -1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum <= target) {
                maxSum = max(maxSum , sum);
                left++;
            }
            else {
                right--;
            }
        }
        return maxSum;
    }