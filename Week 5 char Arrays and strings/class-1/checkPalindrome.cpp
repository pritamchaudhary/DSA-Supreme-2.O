// check palindrome

#include<iostream>
#include<string.h>
using namespace std;

bool checkPalindrome(char ch[], int n){
    int i = 0;
    int j = n-1;
    while(i <= j){
        if(ch[i] == ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    char ch[100];
    cin.getline(ch, 100);

    int length = strlen(ch);
    
    bool isPalindrome = checkPalindrome(ch, length);
    if(isPalindrome){
        cout<<"valid palindrome"<<endl;
    }
    else{
        cout<< "Not a valid palindrome"<<endl;
    }
    
    return 0;
}