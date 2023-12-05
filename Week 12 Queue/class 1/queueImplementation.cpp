// queue implementation from scratch

#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
        // check full
        if(rear == size - 1){
            cout<< "Queue overflow"<<endl;
            return;
        }
        // empty case
        else if(rear == -1 && front == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            // normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        // check underflow
        if(front == -1 && rear == -1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        else if(front == rear){
            // empty case -> single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }
        else{
            return rear - front + 1;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"No element in queue, cannot give front element"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getRear(){
        if(rear == -1){
            cout<< "No element in queue, cannot give rear element"<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    void print(){
        cout<<"printing queue: ";
        for(int i=0; i<size; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q(5);
    q.print();
    
    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    cout<< "size of queue: "<<q.getSize()<<endl;

    q.pop();
    q.print();

    cout<< "size of queue: "<<q.getSize()<<endl;
    cout<<"Queue is empty or not: "<<q.isEmpty()<<endl;

    q.push(100);
    q.print();

    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.print();
    // cout<< q.getSize()<<endl;
    // q.getRear();
    // q.getFront();

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    return 0;
}