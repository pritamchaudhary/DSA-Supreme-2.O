// leetcode 416. Partition Equal Subset Sum using Tabulation space optimized

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool solveUsingTabulationSpaceOptimized(vector<int>& arr, int target){
        int n = arr.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        curr[target] = 1;
        next[target] = 1;

        for(int ind=n-1; ind>=0; ind--){
            for(int s=target; s>=0; s--){
                bool include = 0;
                if(s+arr[ind] <= target){
                    include = next[s+arr[ind]];
                }
                bool exclude = next[s];
                curr[s] = (include || exclude);
            }
            // shifting
            next = curr;
        }
        return next[0];
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
        bool ans = solveUsingTabulationSpaceOptimized(nums, target);
        return ans;
    }
};