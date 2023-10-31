// leetcode 72. Edit Distance

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

            // Insert a character
            // Delete a character
            // Replace a character

#include<iostream>
using namespace std;

class Solution {
public:
    int solve(string& word1, string& word2, int i, int j){
        // base case
        if(i >= word1.length()){
            return word2.length()-j;
        }
        if(j >= word2.length()){
            return word1.length()-i;
        }

        int ans = 0;
        if(word1[i] == word2[j]){
            // match
            ans = 0 + solve(word1, word2, i+1, j+1);
        }
        else{
            // not match
            // perform operation
            // insert
            int option1 = 1 + solve(word1, word2, i, j+1);
            // remove
            int option2 = 1 + solve(word1, word2, i+1, j);
            // replace
            int option3 = 1 + solve(word1, word2, i+1, j+1);
            ans = min(option1, min(option2, option3));
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solve(word1, word2, i, j);
        return ans;
    }
};