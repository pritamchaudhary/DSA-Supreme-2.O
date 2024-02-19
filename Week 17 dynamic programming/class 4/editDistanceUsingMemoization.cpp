// leetcode 72. Edit Distance using Memoization

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingMemoization(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        // base case
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }
        // check if ans already exists
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveUsingMemoization(a, b, i+1, j+1, dp);
        }
        else{
            int replace = 1 + solveUsingMemoization(a, b, i+1, j+1, dp);
            int insert = 1 + solveUsingMemoization(a, b, i, j+1, dp);
            int remove = 1 + solveUsingMemoization(a, b, i+1, j, dp);
            ans = min(replace, min(insert, remove));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        int ans = solveUsingMemoization(word1, word2, i, j, dp);
        return ans;
    }
};