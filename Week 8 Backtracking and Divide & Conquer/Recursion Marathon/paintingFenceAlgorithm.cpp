// gfg -> painting fence algorithm

#include<iostream>
using namespace std;

int getPaintWays(int n, int k){
    // base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k+ k * (k-1);
    }

    int ans = (k-1) * (getPaintWays(n-1, k) + getPaintWays(n-2, k));
    return ans;
}

int main(){
    int n = 3;
    int k = 3;
    cout<<getPaintWays(n, k)<<endl;
    
    return 0;
}