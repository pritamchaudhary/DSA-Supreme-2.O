// print all digits of integer

#include<iostream>
using namespace std;

void printAllDigits(int n){
    while(n){
        int onesPlaceDigit = n % 10;
        cout<< "Digits: "<<onesPlaceDigit<<endl;
        n = n/10;
    }
}

int main(){
    int n;
    cout<< "Enter number to see its digits: "<<endl;
    cin>>n;
    printAllDigits(n);
    
    return 0;
}