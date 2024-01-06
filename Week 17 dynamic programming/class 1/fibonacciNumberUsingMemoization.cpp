// leetcode 509. Fibonacci Number

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // top-down approach
    // recursion + memoization approach
    int solveUsingMemoization(int n, vector<int>& dp){
        // base case
        if(n==0 || n==1){
            return n;
        }
        // if answer already exist then return answer
        if(dp[n] != -1){
            return dp[n];
        }
        // step 2:- store and return using dp array
        dp[n] = solveUsingMemoization(n-1, dp) + solveUsingMemoization(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        // step 1:- create dp array
        vector<int> dp(n+1, -1);
        int ans = solveUsingMemoization(n, dp);
        return ans;
    }
};