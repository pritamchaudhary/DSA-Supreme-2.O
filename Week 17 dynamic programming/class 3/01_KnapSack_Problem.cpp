// knapsack problem

#include<iostream>
#include<vector>
using namespace std;

int sovleUsingRecursion(int capacity, int wt[], int profit[], int index, int n){
    // base case
    if(index >= n){
        return 0;
    }
    // include
    int include = 0;
    if(wt[index] <= capacity){
        include = profit[index] + sovleUsingRecursion(capacity-wt[index], wt, profit, index+1, n);
    }
    // exclude
    int exclude = 0 + sovleUsingRecursion(capacity, wt, profit, index+1, n);
    int ans = max(include, exclude);
    return ans;
}

int solveUsingMemoization(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>>&dp){
    // base case
    if(index >= n){
        return 0;
    }

    // ans already exist
    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }
    // include
    int include = 0;
    if(wt[index] <= capacity){
        include = profit[index] + solveUsingMemoization(capacity-wt[index], wt, profit, index+1, n, dp);
    }
    // exclude
    int exclude = 0 + solveUsingMemoization(capacity, wt, profit, index+1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int main(){
    int capacity = 50;
    int wt[3] = {10, 20, 30};
    int profit[3] = {60, 100, 120};
    int index = 0;
    int n = 3;
    int ans = sovleUsingRecursion(capacity, wt, profit, index, n);
    cout<<"max profit: "<<ans<<endl;

    vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));
    int ansUsingMem = solveUsingMemoization(capacity, wt, profit, index, n, dp);
    cout<<"max profit using memoization: "<<ansUsingMem<<endl;
    
    return 0;
}