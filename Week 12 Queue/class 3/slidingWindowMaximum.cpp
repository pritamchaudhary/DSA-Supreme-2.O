// leetcode 239. Sliding Window Maximum

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // process the first window
        for(int i=0; i<k; i++){
            int element = nums[i];
            // remove every smaller elements in queue
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            // insert 
            dq.push_back(i);
        }
        // process the remaining window
        for(int i=k; i<nums.size(); i++){
            // store ans
            ans.push_back(nums[dq.front()]);
            // removal
            // out of range
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }
            // pop smaller element
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            // addition
            dq.push_back(i);
        }
        // store ans of last window
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};