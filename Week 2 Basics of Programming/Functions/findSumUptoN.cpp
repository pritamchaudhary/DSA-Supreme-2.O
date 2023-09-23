#include<iostream>
using namespace std;

// int sumUptoN(int n){
//     int sum = 0;
//     for(int i=1; i<=n; i++){
//         sum += i;
//     }
//     return sum;
// }

void sumUptoN(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    cout<< "Sum is: "<< sum <<endl;
}

int main(){
    // int sum = sumUptoN(16);
    // cout<< "Sum is: "<< sum <<endl;

    sumUptoN(10);
    
    return 0;
}