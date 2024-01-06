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
    int solveUsingTabulation(int n){
        // step 1:- create dp array
        vector<int> dp(n+1, -1);
        // step 2:- analyze base case and fill dp array
        dp[0] = 0;
        if(n==0) return dp[0];
        dp[1] = 1;
        // step 3:- fill remaining dp array
        for(int i=2; i<=n; i++){
            // replace recursive calls with dp array
            // make sure dp array is using looping variable "i"
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int fib(int n) {
        int ans = solveUsingTabulation(n);
        return ans;
    }
};