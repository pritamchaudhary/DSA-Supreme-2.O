// leetcode 1143. Longest Common Subsequence using Tabulation Space Optimized   

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingTabulationSpaceOptimized(string a, string b){
        vector<int> curr(a.length()+1, 0);
        vector<int> next(a.length()+1, 0);
        
        for(int j_index=b.length()-1; j_index>=0; j_index--){
            for(int i_index=a.length()-1; i_index>=0; i_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    ans = 1 + next[i_index+1];
                }
                else{
                    ans = 0 + max(next[i_index], curr[i_index+1]);
                }
                curr[i_index] = ans;
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int ans = solveUsingTabulationSpaceOptimized(text1, text2);
        return ans;
    }
};