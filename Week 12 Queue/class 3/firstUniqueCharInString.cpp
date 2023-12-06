// leetcode 387. First Unique Character in a String

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string str) {
        queue<int> q;
        int freq[26] = {0};

        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            freq[ch-'a']++;
            q.push(i);
            while(!q.empty()){
                if(freq[str[q.front()]-'a'] > 1){
                    q.pop();
                }
                else{
                    break;
                }
            }   
        }
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
};