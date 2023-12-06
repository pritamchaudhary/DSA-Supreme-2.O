// first non-repeating character in a stream

#include<iostream>
#include<queue>
using namespace std;

int main(){
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);

        // find answer
        while(!q.empty()){
            char frontCharacter = q.front();
            if(freq[frontCharacter-'a'] > 1){
                // this is not the answer
                q.pop();
            }
            else{
                // == wala case and this is the answer
                cout<<frontCharacter<<"->";
                break;
            }
        }
        if(q.empty()){
            // no answer found
            cout<<"#"<<"->";
        }
    }
    
    return 0;
}