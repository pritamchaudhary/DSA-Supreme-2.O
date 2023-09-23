#include<iostream>
using namespace std;

// void checkEvenOdd(int n){
//     if(n % 2 == 0){
//         cout<<"Even"<< endl;
//     }
//     else{
//         cout<< "Odd"<< endl;
//     }
// }

// bool checkEven(int n){
//     if(n%2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

bool checkEven(int n){
    if((n & 1) == 0){
        // its an even number
        return true; 
    }
    else{
        // its an odd number
        return false;
    }
}


int main(){
    int n;
    cin>>n;
    bool isEven = checkEven(n);

    if(isEven){
        cout<<n<< " is Even"<< endl;
    }
    else{
        cout<<n<< " is Odd" << endl;
    }
    
    return 0;
}