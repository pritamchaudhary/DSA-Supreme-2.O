// leetcode 852. Peak Index in a Mountain Array

// An array arr is a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start)/2;

        while(start < end){
            // we are in A line and peak exist in right part
            if(arr[mid] < arr[mid+1]){
                start = mid + 1;
            }
            else{
                // either we are in B line or at peak
                end = mid;
            }
            // update mid
            mid = start + (end - start)/2;
        }
        return start;
    }
};