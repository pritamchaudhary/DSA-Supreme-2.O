// leetcode 890. Find and Replace Pattern

// Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void createUpdateMapping(string& str){
        // find mapping
        char start = 'a';
        char mapping[300] = {0};
        for(auto ch : str){
            if(mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }
        // update the string
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // first normalise the pattern
        createUpdateMapping(pattern);

        for(string s : words){
            string tempString = s;

            // normalise tempString
            createUpdateMapping(tempString);

            if(tempString == pattern){
                // it means that string 's' was a valid answer
                ans.push_back(s);
            }
        }
        return ans;
    }
};