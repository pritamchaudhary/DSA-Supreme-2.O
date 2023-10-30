// leetcode 213. House Robber II

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int s, int e){
        // base case
        if(s > e){
            return 0; 
        }
        // rob house at ith index
        int option1 = nums[s] + solve(nums, s+2, e);
        // doesn't rob house at ith index
        int option2 = 0 + solve(nums, s+1, e);
        int finalAns = max(option1, option2);
        return finalAns;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int option1 = solve(nums, 0, n-2);
        int option2 = solve(nums, 1, n-1);
        int ans = max(option1, option2);
        return ans;
    }
};