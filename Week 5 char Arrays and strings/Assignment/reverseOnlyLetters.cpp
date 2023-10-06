// leetcode 917. Reverse Only Letters

// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

#include<iostream>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        int h = s.size()-1;
        while(l < h){
            if(isalpha(s[l]) && isalpha(s[h])){
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if(!isalpha(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
    }
};