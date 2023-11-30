// leetcode 155. Min Stack

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

        // MinStack() initializes the stack object.
        // void push(int val) pushes the element val onto the stack.
        // void pop() removes the element on the top of the stack.
        // int top() gets the top element of the stack.
        // int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include<iostream>
#include<vector>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            // it means, i am inserting first element
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else{
            pair<int, int> p;
            p.first = val;
            int oldMin = st.back().second;
            p.second = min(oldMin, val);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int, int> rightMostPair = st.back();
        return rightMostPair.first;
    }
    
    int getMin() {
        pair<int, int> rightMostPair = st.back();
        return rightMostPair.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */