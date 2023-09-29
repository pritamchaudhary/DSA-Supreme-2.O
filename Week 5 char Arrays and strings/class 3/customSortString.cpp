// leetcode 791. Custom Sort String

// You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    static string str;
    static bool compare(char char1, char char2){
        return (str.find(char1) < str.find(char2));
    }
    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::str;