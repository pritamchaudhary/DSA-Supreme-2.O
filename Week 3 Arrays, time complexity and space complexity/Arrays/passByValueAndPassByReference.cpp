#include<iostream>
using namespace std;

// pass by value

// void solve(int b){
//     b--;
//     cout<< b+10<<endl;
//     return ;
// }

// pass by reference

// void solve(int& b){
//     b--;
//     cout<< b+10 <<endl;
//     return ;
// }

// pass by reference
void solve(int& m){
    m--;
    m = m* 10;
    cout<<m <<endl;
}

int main(){
    // int a = 100;
    // a--;
    // a -= 5;
    // solve(a);
    // cout<<a<< endl;


    int  mark = 90;
    mark++;
    solve(mark);
    cout<< mark <<endl;
    
    return 0;
}