// sieve of eratosthenes

#include<iostream>
#include<vector>
using namespace std;

vector<bool> Sieve(int n){
    // create a sieve array of N size telling isPrime
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    // optimization 2
    for(int i=2; i*i<=n; i++){
        if(sieve[i] == true){
            // int j = i * 2;
            // optimization 1 -> first unmarked number would be i*i as others have been marked by 2 to (i-1)
            int j = i * i;
            while(j <= n){
                sieve[j] = false;
                j += i;
            }
            
        }
    }
    return sieve;
}

int main(){
    vector<bool> sieve = Sieve(25);
    for(int i=0; i<=25; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
}