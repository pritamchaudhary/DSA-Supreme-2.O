// leetcode 322. Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingTabulation(vector<int>& coins, int amount) {
        //step1: done
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        //step2: base case analyse
        dp[0] = 0;
        //for loop
        for( int value = 1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
            
                if(value - coins[i] >= 0) {
                    int recursionKaAns = dp[value - coins[i] ];
                    
                    if(recursionKaAns != INT_MAX) {
                        
                        int ans = 1 + recursionKaAns;
                        mini  = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingTabulation(coins, amount);
        if(ans == INT_MAX)
            return -1;
        else {
            return ans;
        }
    }
};