// painting fence algorithm

#include<iostream>
#include<vector>
using namespace std;

int solveUsingMemoization(int n, int k, vector<int>& dp){
    // base case
    if(n == 1) return k;
    if(n == 2) return (k + k*(k-1));

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (solveUsingMemoization(n-1, k, dp) + solveUsingMemoization(n-2, k, dp)) * (k-1);
    return dp[n];
}

int solveUsingTabulation(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = (k + k*(k-1));
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }
    return dp[n];
}

int solveUsingRecursion(int n, int k){
    // base case
    if(n == 1) return k;
    if(n == 2) return (k + k*(k-1));

    int ans = (solveUsingRecursion(n-1, k) + solveUsingRecursion(n-2, k)) * (k-1);
    return ans;
}

int main(){
    int n = 3;
    int k = 3;
    int ans = solveUsingRecursion(n, k);
    cout<<"ans is: "<<ans<<endl;

    vector<int> dp(n+1, -1);
    long long ansMemoization = solveUsingMemoization(n, k, dp);
    cout<<"ans using memoization: "<<ansMemoization<<endl;

    int ansTabulation = solveUsingTabulation(n, k);
    cout<<"ans using tabulation: "<<ansTabulation<<endl;
    
    return 0;
}