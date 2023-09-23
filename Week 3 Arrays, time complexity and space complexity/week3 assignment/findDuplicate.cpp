// leetcode 287. Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         // positioning method
//         while(nums[0] != nums[nums[0]]){
//             swap(nums[0], nums[nums[0]]);
//         }
//         return nums[0];
//     }
// };


// method 2 -> negative marking method

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            int index = abs(nums[i]);
            // already visited
            if(nums[index] < 0){
                ans = index;
                break;
            }

            // visited mark
            nums[index] *= -1;
        }
        return ans;
    }
};