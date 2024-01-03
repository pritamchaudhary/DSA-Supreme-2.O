
#include<iostream>
using namespace std;

class TrieNode{
    public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val){
        this->value = val;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word){
    cout<<"received word: "<<word<<" for insertion"<<endl;
    // base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        // present
        child = root->children[index];
    }
    else{
        // absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    // recursion
    insertWord(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "donation");
    
    return 0;
}