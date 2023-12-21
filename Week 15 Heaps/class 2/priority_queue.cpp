// priority_queue

#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout<<"top element of heap: "<<pq.top()<<endl;
    cout<<"size: "<<pq.size()<<endl;
    pq.pop();
    cout<<"top element of heap: "<<pq.top()<<endl;

    if(pq.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }

    return 0;
}