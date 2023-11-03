#include<iostream>
#include "MyString.h"

using namespace std;

int main(){
    MyString s("Pritam is the best");
    MyString t = "Mobile";
    cout<<s <<endl;
    cout<<t<<endl;
    cout<< s[0] <<endl;
    cout<< s.find("best") <<endl; 
    return 0;
}