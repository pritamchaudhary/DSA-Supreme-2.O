// leetcode 268. Missing Number

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // xor all values of array
        for(int i=0; i<n; i++){
            ans = ans ^ nums[i];
        }
        // xor all range items [0, N]
        for(int i=0; i<=n; i++){
            ans = ans ^ i;
        }
        return ans;
    }
}; 