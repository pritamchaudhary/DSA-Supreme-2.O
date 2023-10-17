// leetcode 121. Best Time to Buy and Sell Stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit){
        // base case
        if(i == prices.size()){
            return;
        }
        // solution for one case
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        int todaysProfit = prices[i] - minPrice;
        if(todaysProfit > maxProfit){
            maxProfit = todaysProfit;
        }
        // RE
        maxProfitFinder(prices, i+1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};