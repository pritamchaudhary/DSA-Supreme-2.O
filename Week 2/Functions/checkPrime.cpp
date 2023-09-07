#include<iostream>
using namespace std;

bool checkPrime(int n){
    if(n==1 || n==0){
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
    int isPrime = checkPrime(n);
    if(isPrime){
        cout<< "Prime"<< endl;
    }
    else{
        cout<< "Not Prime"<<endl;
    }
    
    return 0;
}