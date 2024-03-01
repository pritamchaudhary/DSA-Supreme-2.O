// leetcode 416. Partition Equal Subset Sum using Tabulation

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool solveUsingTabulation(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int row=0; row<=n; row++){
            dp[row][target] = 1;
        }
        for(int ind=n-1; ind>=0; ind--){
            for(int s=target; s>=0; s--){
                bool include = 0;
                if(s+arr[ind] <= target){
                    include = dp[ind+1][s+arr[ind]];
                }
                bool exclude = dp[ind+1][s];
                dp[ind][s] = (include || exclude);
            }
        }
        return dp[0][0];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        if(totalSum & 1){
            // odd can't be partitioned
            return false;
        }
        int target = totalSum / 2;
        bool ans = solveUsingTabulation(nums, target);
        return ans;
    }
};