// leetcode 322. Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
        //base case
        if(amount == 0) {
            return 0;
        }
        //already ans exist
        if(dp[amount] != -1) {
            return dp[amount];
        }
        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            //find ans using ith coin
            //call recursion only for valid amounts i.e. >=0  wale amounts
            if(amount - coins[i] >= 0) {
                int recursionKaAns = solveUsingMem(coins, amount - coins[i], dp);
                //if a valid answeer
                if(recursionKaAns != INT_MAX) {
                    //considering uage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini  = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, -1);
        int ans = solveUsingMem(coins, amount, dp);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};