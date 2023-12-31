// leetcode 1405. Longest Happy String

// A string s is called happy if it satisfies the following conditions:

    // s only contains the letters 'a', 'b', and 'c'.
    // s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    // s contains at most a occurrences of the letter 'a'.
    // s contains at most b occurrences of the letter 'b'.
    // s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

#include<iostream>
#include<queue>
using namespace std;

class Info{
    public:
        char val;
        int count;
    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare{
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, compare> maxHeap;
        if(a > 0) {
            Info temp('a', a);
            maxHeap.push(temp);
        }
        if(b > 0) {
            Info temp('b', b);
            maxHeap.push(temp);
        }
        if(c > 0) {
            Info temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";
        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();
            
            if(first.count >=2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else {
                ans.push_back(first.val);
                first.count--;
            } 

            if(second.count >=2 && second.count >= first.count) {
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count -= 2;
            }
            else {
                ans.push_back(second.val);
                second.count--;
            } 

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }       
        }

        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            if(first.count >=2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else {
                ans.push_back(first.val);
                first.count--;
            } 
        } 
        return ans;
    }
};