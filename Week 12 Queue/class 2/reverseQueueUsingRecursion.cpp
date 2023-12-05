// reverse a queue using recursion

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    // base case
    if(q.empty()){
        return;
    }

    int temp = q.front();
    q.pop();

    // recursion call
    reverseQueue(q);

    q.push(temp);
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