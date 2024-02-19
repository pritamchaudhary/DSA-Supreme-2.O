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
    int solveUsingRecursion(string& a, string& b, int i, int j){
        // base case
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveUsingRecursion(a, b, i+1, j+1);
        }
        else{
            int replace = 1 + solveUsingRecursion(a, b, i+1, j+1);
            int insert = 1 + solveUsingRecursion(a, b, i, j+1);
            int remove = 1 + solveUsingRecursion(a, b, i+1, j);
            ans = min(replace, min(insert, remove));
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingRecursion(word1, word2, i, j);
        return ans;
    }
};