// leetcode 724. Find Pivot Index

// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int prefixSumApproach(vector<int>& nums){
       int n = nums.size();
       vector<int> lSum(n, 0);
       vector<int> rSum(n, 0);

    // calculating leftsum array
       for(int i=1; i<n; i++){
           lSum[i] = lSum[i-1] + nums[i-1];
       }
    // calculating rightsum array
       for(int i=n-2; i>=0; i--){
           rSum[i] = rSum[i+1] + nums[i+1];
       }
    //  check
        for(int i=0; i<n; i++){
            if(lSum[i] == rSum[i]){
                return i;
            }
        }
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
    }
};