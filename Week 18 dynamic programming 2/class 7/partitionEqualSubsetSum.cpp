// leetcode 416. Partition Equal Subset Sum using recursion

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool solveUsingRecursion(vector<int>& nums, int index, int sum, int target){
        if(index >= nums.size()){
            return 0;
        }
        if(sum > target){
            return 0;
        }
        if(sum == target){
            return true;
        }
        bool include = solveUsingRecursion(nums, index+1, sum+nums[index], target);
        bool exclude = solveUsingRecursion(nums, index+1, sum, target);
        return include || exclude;
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
        bool ans = solveUsingRecursion(nums, index, currSum, target);
        return ans;
    }
};