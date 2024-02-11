// leetcode 1143. Longest Common Subsequence using Memoization

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingMemoization(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        // base case
        if(i >= a.length()){
            return 0;
        }
        if(j >= b.length()){
            return 0;
        }
        // check if ans already exist
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // recursion call
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveUsingMemoization(a, b, i+1, j+1, dp);
        }
        else{
            ans = 0 + max(solveUsingMemoization(a, b, i+1, j, dp), solveUsingMemoization(a, b, i, j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        int ans = solveUsingMemoization(text1, text2, i, j, dp);
        return ans;
    }
};