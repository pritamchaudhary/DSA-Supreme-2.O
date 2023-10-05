// fast exponentiation

// Given two positive integers A and B, find GCD of A and B.

#include<iostream>
using namespace std;

int fastExponentiation(int a, int b){
    int ans = 1;
    while(b > 0){
        // if b is odd
        if(b & 1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1; //b = b/2;
    }
    return ans;
}

int main(){
    int a = 5, b = 3;
    int ans = fastExponentiation(a, b);
    cout<<ans<<endl;
    
    return 0;
}