// leetcode 300. Longest Increasing Subsequence using Tabulation space optimized

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingTabulationSpaceOptimized(vector<int>& nums){
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        for(int curr_index=n-1; curr_index>=0; curr_index--){
            for(int prev_index=curr_index-1; prev_index>=-1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + nextRow[curr_index+1];
                }
                int exclude = 0 + nextRow[prev_index+1];
                currRow[prev_index+1] = max(include, exclude);
            }
            // shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int ans = solveUsingTabulationSpaceOptimized(nums);
        return ans;
    }
};