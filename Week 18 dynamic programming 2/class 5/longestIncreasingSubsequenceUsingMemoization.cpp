// leetcode 300. Longest Increasing Subsequence using Memoization

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingMemoization(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        // base case
        if(curr >= nums.size()){
            return 0;
        }
        // if ans already exists
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMemoization(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveUsingMemoization(nums, curr+1, prev, dp);
        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMemoization(nums, curr, prev, dp);
        return ans;
    }
};