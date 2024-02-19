// leetcode 72. Edit Distance using Tabulation space optimized

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
    int solveUsingTabulationSO(string a, string b){
        vector<int> curr(a.length()+1, 0);
        vector<int> next(a.length()+1, 0);
        for(int row=0; row<=a.length(); row++){
            next[row] = a.length()-row;
        }

        for(int j_index=b.length()-1; j_index>=0; j_index--){
            // har naye col ke last dabbe me ans insert karo 
            curr[a.length()] = b.length()-j_index;
            for(int i_index=a.length()-1; i_index>=0; i_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    ans = 0 + next[i_index+1];
                }
                else{
                    int replace = 1 + next[i_index+1];
                    int insert = 1 + next[i_index];
                    int remove = 1 + curr[i_index+1];
                    ans = min(replace, min(insert, remove));
                }
                curr[i_index] = ans;
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int ans = solveUsingTabulationSO(word1, word2);
        return ans;
    }
};