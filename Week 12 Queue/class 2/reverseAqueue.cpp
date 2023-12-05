// reverse a queue

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;
    // one by one queue se element lo and stack me push karo
    while(!q.empty()){
        int frontElement = q.front();
        q.pop();
        s.push(frontElement);
    }
    // one by one stack se element lo and queue me push karo
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseQueue(q);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout<<element<<" ";
    }

    return 0;
}