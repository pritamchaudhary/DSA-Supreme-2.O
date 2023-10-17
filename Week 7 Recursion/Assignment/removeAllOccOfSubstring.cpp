// leetcode 1910. Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

#include<iostream>
using namespace std;

class Solution {
public:
    void removeOccRE(string& s, string& part){
        int found = s.find(part);
        if(found != string::npos){
            // part string has been found, remove it
            string left_part = s.substr(0, found);
            string right_part = s.substr(found+part.size(), s.size());
            s = left_part + right_part;

            removeOccRE(s, part);
        }
        else{
            // base case
            return;
        }
    }

    string removeOccurrences(string s, string part) {
        removeOccRE(s, part);
        return s;
    }
};