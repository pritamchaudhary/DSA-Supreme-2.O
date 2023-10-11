// return nth fibonacci

#include<iostream>
using namespace std;

int fib(int n){
    // base case
    if(n == 0) return 1;
    if(n == 1) return 1;

    // recursive relation
    int ans = fib(n-1) + fib(n-1);
    return ans;
}

int main(){
    cout<<fib(5)<<endl;
    
    return 0;
}