// create number using digits

#include<iostream>
using namespace std;

int createNumberUsingDigits(int numberOfDigits){
    int num = 0;
    for(int i=0; i<numberOfDigits; i++){
        cout<< "Enter Digits: " <<endl;
        int digit;
        cin>>digit;
        num = num * 10 + digit;
        cout<<"Number created so far: "<<num<<endl;
    }
    return num;
}

int main(){
    int numberOfDigits;
    cin>>numberOfDigits;
    int num = createNumberUsingDigits(numberOfDigits);

    cout<<"Number created by digits: "<<num<<endl;
    
    return 0;
}