// subsequences of string

#include<iostream>
#include<vector>
using namespace std;

void findSubsequences(string str, string output, int index, vector<string>& ans){
    // base case
    if(index >= str.length()){
        // cout<<"->"<<output<<endl;
        ans.push_back(output);
        return;
    }
    char ch = str[index];

    // include
    output.push_back(ch);
    findSubsequences(str, output, index+1, ans);

    // exclude
    output.pop_back();
    findSubsequences(str, output, index+1, ans);

    // // exclude
    // findSubsequences(str, output, index+1);

    // // include
    // output.push_back(ch);
    // findSubsequences(str, output, index+1);
}

int main(){
    string str = "abc";
    string output = "";
    int index = 0;
    vector<string> ans;
    findSubsequences(str, output, index, ans);

    for(string s: ans){
        cout<<"->"<<s<<endl;
    }
    
    return 0;
}