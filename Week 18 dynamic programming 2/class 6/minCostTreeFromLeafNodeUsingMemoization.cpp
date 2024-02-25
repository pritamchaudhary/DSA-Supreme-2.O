// leetcode 1130. Minimum Cost Tree From Leaf Values using Memoization

// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int solveUsingMemoization(vector<int>& arr, map<pair<int,int>,int>& maxi, int s, int e, vector<vector<int>>& dp){
        // base case
        if(s >= e){
            return 0;
        }
        // if ans already exists
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int ans = INT_MAX;
        for(int i=s; i<e; i++){
            // i is used for partitioning
            ans = min(ans, (maxi[{s, i}] * maxi[{i+1, e}]) + solveUsingMemoization(arr, maxi, s, i, dp) + solveUsingMemoization(arr, maxi, i+1, e, dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for(int i=0; i<n; i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        int start = 0;
        int end = n-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMemoization(arr, maxi, start, end, dp);
        return ans;
    }
};