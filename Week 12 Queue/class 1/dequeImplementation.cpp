// Doubly ended queue implementation from scratch

#include<iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        arr = new int [size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val){
        // overflow 
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout<<"Overfrlow"<<endl;
        }
        // empty case-> first element
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular nature
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        // normal flow
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pushFront(int val){
        // overflow
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout<<"Overflow"<<endl;
        }
        // empty case-> first element
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        // circular nature
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = val;
        }
        // normal flow
        else{
            front--;
            arr[front] = val;
        }
    }

    void popFront(){
        // underflow
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
        }
        // single element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if(front == size - 1){
            arr[front] = -1;
            front = 0;
        }
        // normal flow
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popBack(){
        // underflow
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
        }
        // single element
        else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if(rear == 0){
            arr[rear] = -1;
            rear = size-1;
        }
        // normal flow
        else{
            arr[rear] = -1;
            rear--;
        }
    }

    void print(){
        cout<<"front: "<<front<<" Rear: "<<rear<<endl;
        cout<<"printing Deque: ";
        for(int i=0; i<size; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    Deque dq(5);
    dq.print();

    dq.pushBack(10);
    dq.print();

    dq.pushBack(20);
    dq.print();

    dq.pushFront(30);
    dq.print();
    
    return 0;
}