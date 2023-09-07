// function to find factorial of a number

#include<iostream>
using namespace std;

long long int factorial(long long int n){
    if(n == 0 || n == 1){
        return 1;
    }
    long long int fact = 1;
    for(int i=1; i<=n; i++){
        fact = fact * i;
    }
    
    return fact;
}

int main(){
    int n;
    cin>>n;
    long long int ans = factorial(n);
    cout<< "factorial is: "<< ans << endl;
    
    return 0;
}