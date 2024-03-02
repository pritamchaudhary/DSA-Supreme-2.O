// leetcode 1155. Number of Dice Rolls With Target Sum using Memoization

// You have n dice, and each dice has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingMemoization(int n, int k, int target, vector<vector<int>>& dp){
        // base case
        if(n == 0 && target == 0) return 1;
        if(n == 0 && target != 0) return 0;
        if(n != 0 && target == 0) return 0;
        // if ans already exists
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i=1; i<=k; i++){
            int recAns = 0;
            if(target-i >= 0){
                recAns = (solveUsingMemoization(n-1, k, target-i, dp)) % MOD;
            }
            ans = (ans % MOD + recAns % MOD) % MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        int ans = solveUsingMemoization(n, k, target, dp);
        return ans;
    }
};