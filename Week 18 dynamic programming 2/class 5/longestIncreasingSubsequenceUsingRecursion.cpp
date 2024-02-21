// leetcode 300. Longest Increasing Subsequence using Recursion

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev){
        // base case
        if(curr >= nums.size()){
            return 0;
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingRecursion(nums, curr+1, curr);
        }
        int exclude = 0 + solveUsingRecursion(nums, curr+1, prev);
        int ans = max(include, exclude);
        return ans;;
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        int ans = solveUsingRecursion(nums, curr, prev);
        return ans;
    }
};