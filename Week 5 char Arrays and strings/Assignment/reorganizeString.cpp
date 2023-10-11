// leetcode 767. Reorganize String

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

#include<iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for(int i=0; i<s.size(); i++){
            hash[s[i] - 'a']++;
        }
        // find the most frequent char
        char max_freq_char;
        int max_freq = INT_MIN;
        for(int i=0; i<26; i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }
        int index = 0;
        while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }
        if(max_freq != 0){
            return "";
        }
        hash[max_freq_char - 'a'] = 0;

        // let's place the rest of the characters
        for(int i=0; i<26; i++){
            while(hash[i] > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};