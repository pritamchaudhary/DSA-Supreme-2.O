// leetcode 198. House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingMemoization(vector<int>& nums, int index, vector<int>& dp){
        // base case
        if(index >= nums.size()){
            return 0;
        }
        // ans already exists
        if(dp[index] != -1){
            return dp[index];
        }
        // recursive relation
        int include = nums[index] + solveUsingMemoization(nums, index+2, dp);
        int exclude = 0 + solveUsingMemoization(nums, index+1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = solveUsingMemoization(nums, index, dp);
        return ans;
    }
};