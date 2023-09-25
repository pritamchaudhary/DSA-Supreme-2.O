// leetcode 532. K-diff Pairs in an Array

// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

        // 0 <= i, j < nums.length
        // i != j
        // |nums[i] - nums[j]| == k
        // Notice that |val| denotes the absolute value of val.

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int target){
        int n = nums.size();
        int end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(binarySearch(nums, i+1, nums[i]+k) != -1){
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
    }
};