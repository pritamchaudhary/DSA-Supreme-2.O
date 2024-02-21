// leetcode 300. Longest Increasing Subsequence using Binary Search

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingBinarySearch(vector<int>& nums){
        vector<int> ans;
        // initial state
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // replace
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int ans = solveUsingBinarySearch(nums);
        return ans;
    }
};