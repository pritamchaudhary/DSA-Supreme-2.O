// leetcode 658. Find K Closest Elements

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

        // |a - x| < |b - x|, or
        // |a - x| == |b - x| and a < b

#include<iostream>
#include<vector>
using namespace std;


// using two pointer approach
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high - low >= k){
            if(x-arr[low] > arr[high]-x){
                low++;
            }
            else{
                high--;
            }
        }
        vector<int>ans;
        for(int i=low; i<=high; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};