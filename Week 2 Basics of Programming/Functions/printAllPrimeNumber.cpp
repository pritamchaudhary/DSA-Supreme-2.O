// function to print all prime number from 1 to N

#include<iostream>
using namespace std;

bool checkPrime(int n){
    if(n == 1 || n == 0){
        return false;
    }
    for(int i=2; i<n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i = 1; i<= n ; i++){
        bool isiPrime = checkPrime(i);
        if(isiPrime){
            cout<< i << " ";
        }
    }
    
    return 0;
}