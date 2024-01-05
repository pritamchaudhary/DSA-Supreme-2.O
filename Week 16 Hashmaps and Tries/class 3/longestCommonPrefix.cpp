// leetocde 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
  public:
    char value;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char val) {
      this->value = val;
      for(int i=0; i<26; i++) {
        children[i] = NULL;
      }
      this->isTerminal = false;
      this->childCount = 0;
    }
};

class Solution {
public:
    //insertion
    void insertWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL) {
        //present
        child = root->children[index];
    }
    else {
        //absent
        child = new TrieNode(ch);
        root->children[index] = child;
        root->childCount++;
    }
    //recursion
    insertWord(child, word.substr(1));
    }

    void findLCP( string& ans, TrieNode* root) {
        //base case
        if(root->isTerminal == true) {
            return;
        }
        //abhi main root node pr hu 
        TrieNode* child;
        if(root->childCount == 1) {
            
            //child tk jao
            for(int i=0; i<26; i++) {
                if(root->children[i] != NULL) {
                    child = root->children[i];
                }
            }
            //ans me store karwao
            ans.push_back(child->value);
        }
        else {
            return;
        }
        //recursion 
        findLCP(ans, child);
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        //insert all strings
        for(auto str: strs) {
            insertWord(root, str);
        }
        string ans = "";
        //string str = strs[0];
        findLCP( ans, root);
        return ans;
        }
};