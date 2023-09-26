// leetcode 1047. Remove All Adjacent Duplicates In String

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;
        while(index < s.length()){
            // rightmost character of ans and current character of string s
            if(ans.length() > 0 && ans[ans.length()-1] == s[index]){
                // pop
                ans.pop_back();
            }
            else{
                // push
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};