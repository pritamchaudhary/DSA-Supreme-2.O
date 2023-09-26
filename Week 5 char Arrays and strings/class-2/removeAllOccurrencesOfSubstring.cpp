// leetcode 1910. Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            // if inside loop, it means that part exists in s string
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};