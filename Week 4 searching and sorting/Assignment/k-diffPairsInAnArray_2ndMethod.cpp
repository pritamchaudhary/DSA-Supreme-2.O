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

// using two pointer approach

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        int i=0;
        int j=1;
        while(j < nums.size()){
            int diff = (nums[j] - nums[i]);
            if(diff == k){
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            else if(diff < k){
                j++;
            }
            else{
                i++;
            }
            if(i == j){
                j++;
            }
        }
        return ans.size();
    }
};