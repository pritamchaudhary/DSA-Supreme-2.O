// leetcode 1130. Minimum Cost Tree From Leaf Values using Tabulation

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
    int solveUsingTabulation(vector<int>& arr, map<pair<int, int>, int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
        for(int s_index=n; s_index>=0; s_index--){
            for(int e_index=0; e_index<=n-1; e_index++){
                if(s_index >= e_index){
                    continue;
                }
                int ans = INT_MAX;
                for(int i=s_index; i<e_index; i++){
                    // i is used for partitioning
                    ans = min(ans, (maxi[{s_index, i}] * maxi[{i+1, e_index}]) + dp[s_index][i] + dp[i+1][e_index]);
                }
                dp[s_index][e_index] = ans;
            }
        }
        return dp[0][n-1];
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
        int ans = solveUsingTabulation(arr, maxi);
        return ans;
    }
};