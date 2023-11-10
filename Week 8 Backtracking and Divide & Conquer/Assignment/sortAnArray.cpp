// leetcode 912. Sort an Array

// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

// in place merge sort

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void mergeInPlace(vector<int>& nums, int start, int mid, int end){
        int total_size = end - start + 1;
        int gap = (total_size / 2) + (total_size % 2);
        while(gap > 0){
            int i = start;
            int j = i + gap;
            while(j <= end){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            }
            gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
        }
    }

    void mergeSort(vector<int>& nums, int start, int end){
        // base case
        if(start >= end) return;
        int mid = start + (end-start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        mergeInPlace(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};