// leetcode 72. Edit Distance using Tabulation

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
    int solveUsingTabulation(string a, string b){
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
        for(int col=0; col<=b.length(); col++){
            dp[a.length()][col] = b.length()-col;
        }
        for(int row=0; row<=a.length(); row++){
            dp[row][b.length()] = a.length()-row;
        }

        for(int i_index=a.length()-1; i_index>=0; i_index--){
            for(int j_index=b.length()-1; j_index>=0; j_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    ans = 0 + dp[i_index+1][j_index+1];
                }
                else{
                    int replace = 1 + dp[i_index+1][j_index+1];
                    int insert = 1 + dp[i_index][j_index+1];
                    int remove = 1 + dp[i_index+1][j_index];
                    ans = min(replace, min(insert, remove));
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int ans = solveUsingTabulation(word1, word2);
        return ans;
    }
};