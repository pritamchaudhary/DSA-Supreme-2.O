// 2 to the power of n

#include<iostream>
using namespace std;

int pow(int n){
    // base case
    if(n == 0) return 1;

    int ans = 2 * pow(n-1);
    return ans;
}

int main(){
    cout<<pow(5)<<endl;
    
    return 0;
}