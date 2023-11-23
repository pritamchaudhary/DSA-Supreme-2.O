// sort a stack

#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& st, int element){
    // base case
    if(st.empty() || element > st.top()){
        st.push(element);
        return;
    }
    // 1 case solve
    int temp = st.top();
    st.pop();
    // recursion call
    insertSorted(st, element);
    // backtrack
    st.push(temp);
}

void sortStack(stack<int>& st){
    // base case
    if(st.empty()){
        return;
    }
    // 1 case solve
    int temp = st.top();
    st.pop();
    // recursion call
    sortStack(st);
    // backtrack
    insertSorted(st, temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(7);
    st.push(12);
    st.push(5);
    st.push(11);

    sortStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}