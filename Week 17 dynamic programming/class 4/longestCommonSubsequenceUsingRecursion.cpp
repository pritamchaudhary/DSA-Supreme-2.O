// leetcode 1143. Longest Common Subsequence using Recursion

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

#include<iostream>
using namespace std;

class Solution {
public:
    int solveUsingRecursion(string a, string b, int i, int j){
        // base case
        if(i >= a.length()){
            return 0;
        }
        if(j >= b.length()){
            return 0;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveUsingRecursion(a, b, i+1, j+1);
        }
        else{
            ans = 0 + max(solveUsingRecursion(a, b, i+1, j), solveUsingRecursion(a, b, i, j+1));
        }
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingRecursion(text1, text2, i, j);
        return ans;
    }
};