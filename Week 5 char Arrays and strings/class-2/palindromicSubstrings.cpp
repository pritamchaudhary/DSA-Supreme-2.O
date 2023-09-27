// leetcode 647. Palindromic Substrings

// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

#include<iostream>
using namespace std;

class Solution {
public:
    int expand(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int center=0; center<s.length(); center++){
            // ODD
            int oddAns = expand(s, center, center);
            // EVEN
            int evenAns = expand(s, center, center+1);
            totalCount = totalCount + oddAns + evenAns;
        }
        return totalCount;
    }
};