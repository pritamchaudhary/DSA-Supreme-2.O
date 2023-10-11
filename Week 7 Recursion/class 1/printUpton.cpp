// print upto n

#include<iostream>
using namespace std;

void printUptoN(int n){
    // base case
    if(n == 1){
        cout<<1<<" ";
        return;
    }

    printUptoN(n-1);
    cout<<n<<" ";
}

int main(){
    printUptoN(10);
    
    return 0;
}