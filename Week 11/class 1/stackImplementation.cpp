// stack implementation

#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top == size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top] = data;
        }       
    }

    void pop(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top--;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        } 
    }

    int getSize(){
        return top+1;
    }

    void print(){
        cout<<"Top: "<<top<<endl;
        cout<<"Top element: "<<getTop()<<endl;
        cout<<"Stack: ";
        for(int i=0; i<getSize(); i++){
            cout<<arr[i]<<" ";
        } 
        cout<<endl<<endl;
    }
};

int main(){
    // creation
    Stack st(8);

    // push
    st.push(10);
    st.print();

    st.push(20);
    st.print();

    st.push(30);
    st.print();

    st.push(40);
    st.print();

    cout<<"Top element: "<<st.getTop()<<endl;
    cout<<"Size of stack: "<<st.getSize()<<endl;

    if(st.isEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }

    // st.push(40);
    // st.print();

    // st.push(40);
    // st.print();

    // st.push(40);
    // st.print();

    // st.push(40);
    // st.print();

    // st.push(40);
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();
    
    return 0;
}