// last occurrence of a char
// method 2 -> Right to left

#include<iostream>
using namespace std;

void lastOccRtoL(string& s, char x, int index, int& ans){
    // base case
    if(index < 0){
        return;
    }
    // processing
    if(s[index] == x){
        ans = index;
        return;
    }
    // recursive call
    lastOccRtoL(s, x, index-1, ans);
}

int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;
    int index = s.length()-1;
    int ans = -1;
    lastOccRtoL(s, x, index, ans);
    cout<<ans<<endl;

    return 0;
}