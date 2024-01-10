// leetcode 198. House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingTabulation(vector<int>& nums){
        int n = nums.size();
        // step 1
        vector<int> dp(n, -1);
        // step 2
        dp[n-1] = nums[n-1];
        for(int index = n-2; index >= 0; index--){
            int tempAns = 0;
            if(index+2 < n){
                tempAns = dp[index + 2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index + 1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int ans = solveUsingTabulation(nums);
        return ans;
    }
};