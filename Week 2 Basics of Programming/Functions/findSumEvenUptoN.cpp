#include<iostream>
using namespace std;

void sumEvenUptoN(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(i % 2 == 0){
            sum = sum + i;
        }
    }
    cout<< "Even Sum is: "<< sum <<endl;
}

int main(){
    sumEvenUptoN(10);
    
    return 0;
}