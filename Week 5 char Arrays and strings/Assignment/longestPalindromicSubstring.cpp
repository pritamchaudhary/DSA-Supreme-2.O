// leetcode 5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int start , int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(s, i, j)){
                    string t = s.substr(i, j-i+1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};