// painting fence algorithm using tabulation space optimized

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTabulation(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = (k + k*(k-1));
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }
    return dp[n];
}

int solveUsingTabulationSO(int n, int k){
    int prev2 = k;
    int prev1 = k + k*(k-1);
    if(n==1){
        return prev2;
    }
    if(n==2){
        return prev1;
    }
    int curr;
    for(int i=3; i<=n; i++){
        curr = (prev1 + prev2) * (k-1);
        // shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(){
    int n = 3;
    int k = 3;

    int ansTabulationSO = solveUsingTabulationSO(n, k);
    cout<<"ans using tabulation space optimized: "<<ansTabulationSO<<endl;
    
    return 0;
}