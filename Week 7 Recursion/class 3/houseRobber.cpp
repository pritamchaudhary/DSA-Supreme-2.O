// leetcode 198. House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int size, int index){
        // base case
        if(index >= size) return 0;
        // sol for one case
        int option1 = nums[index] + solve(nums, size, index+2);
        int option2 = 0 + solve(nums, size, index+1);
        int finalAns = max(option1, option2);
        return finalAns;
        
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        int ans = solve(nums, size, index);
        return ans;
    }
};