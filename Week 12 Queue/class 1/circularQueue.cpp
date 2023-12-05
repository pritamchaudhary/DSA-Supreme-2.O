// circular queue

#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int size){
        arr = new int [size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
        // overflow
        if((front == 0 && rear == size-1) || (rear == front - 1)){
            cout<<"Overflow"<<endl;
        }
        // empty case -> first element
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

    void pop(){
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

    void print(){
        cout<<"front: "<<front<<" Rear: "<<rear<<endl;
        cout<<"printing Queue: ";
        for(int i=0; i<size; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    CircularQueue q(5);
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

    q.push(60);

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();

    q.push(110);
    q.print();

    q.push(120);
    q.print();

    q.push(130);
    q.print();
    
    return 0;
}