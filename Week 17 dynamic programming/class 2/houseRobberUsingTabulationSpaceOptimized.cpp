// leetcode 198. House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingTabulationSpaceOptimized(vector<int>& nums){
        int n = nums.size();
        int prev = nums[n-1];
        int next = 0;
        int curr = 0;
        for(int index = n-2; index >= 0; index--){
            int tempAns = 0;
            if(index+2 < n){
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
            curr = max(include, exclude);

            next = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int ans = solveUsingTabulationSpaceOptimized(nums);
        return ans;
    }
};