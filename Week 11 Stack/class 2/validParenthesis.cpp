// leetcode 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

        // Open brackets must be closed by the same type of brackets.
        // Open brackets must be closed in the correct order.
        // Every close bracket has a corresponding open bracket of the same type.

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                // for open bracket -> just push
                st.push(ch);
            }
            else{
                // closing bracket
                if(!st.empty()){
                    if(ch == ')' && st.top() == '('){
                    st.pop();
                    }
                    else if(ch == '}' && st.top() == '{'){
                        st.pop();
                    }
                    else if(ch == ']' && st.top() == '['){
                        st.pop();
                    }
                    else{
                        // no match 
                        return false;
                    }
                }
                else{
                    return false;
                }
                
            }
        }
        if(st.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};