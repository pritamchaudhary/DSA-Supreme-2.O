// return sum upto n

#include<iostream>
using namespace std;

int sum(int n){
    // base case
    if(n == 1) return 1;

    // recursive relation
    int ans = n + sum(n-1);
    return ans;
}

int main(){
    cout<<sum(5)<<endl;
    
    return 0;
}