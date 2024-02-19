// leetcode 516. Longest Palindromic Subsequence

// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

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

    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = solveUsingTabulationSpaceOptimized(a, s);
        return ans;
    }
};