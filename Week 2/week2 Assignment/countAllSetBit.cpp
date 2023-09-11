// count all set bits

#include<iostream>
using namespace std;

// first method

// int countSetBit(int n){
//     int count = 0;
//     while(n > 0){
//         int bit = n % 2;
//         if(bit == 1){
//             count++;
//         }
//         n = n/2;
//     }
//     return count;
// }

// second method -> bitwise method

int countSetBit(int n){
    int count = 0;
    while(n > 0){
        int bit = (n & 1);
        if(bit == 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main(){
    int n;
    cin>> n;
    int setBitCount = countSetBit(n);
    cout<< setBitCount<<endl;
}