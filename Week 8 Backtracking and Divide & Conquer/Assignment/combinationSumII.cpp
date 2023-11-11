// leetcode 40. Combination Sum II

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void combinationSum_helper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans, int index){
        // base case
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_helper(candidates, target-candidates[i], v, ans, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum_helper(candidates, target, v, ans, 0);
        return ans;
    }
};