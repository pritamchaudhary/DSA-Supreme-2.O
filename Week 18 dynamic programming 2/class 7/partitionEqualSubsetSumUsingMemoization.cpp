// leetcode 416. Partition Equal Subset Sum using Memoization

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool solveUsingMemoization(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp){
        if(index >= nums.size()){
            return 0;
        }
        if(sum > target){
            return 0;
        }
        if(sum == target){
            return true;
        }
        // if ans already exists
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        bool include = solveUsingMemoization(nums, index+1, sum+nums[index], target, dp);
        bool exclude = solveUsingMemoization(nums, index+1, sum, target, dp);
        return dp[index][sum] = (include || exclude);
    }

    bool canPartition(vector<int>& nums) {
        int index = 0;
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        if(totalSum & 1){
            // odd can't be partitioned
            return false;
        }
        int target = totalSum / 2;
        int currSum = 0;
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
        bool ans = solveUsingMemoization(nums, index, currSum, target, dp);
        return ans;
    }
};