// last occurrence of a char

#include<iostream>
using namespace std;

void lastOccLtoR(string& s, char x, int index, int& ans){
    // base case
    if(index >= s.length()){
        return;
    }
    // processing
    if(s[index] == x){
        ans = index;
    }
    // recursive call
    lastOccLtoR(s, x, index+1, ans);
}

int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;
    int index = 0;
    int ans = -1;
    lastOccLtoR(s, x, index, ans);
    cout<<ans<<endl;

    return 0;
}