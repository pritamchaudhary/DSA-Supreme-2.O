// first negative integer in every window of k

#include<iostream>
#include<deque>
using namespace std;

void printFirstNegative(int *arr, int n, int k){
    deque<int> dq;
    // process first k elements -> first window
    for(int index = 0; index < k; index++){
        int element = arr[index];
        if(element < 0){
            dq.push_back(index);
        }
    }
    // process remaining windows -> removal and addition
    for(int index = k; index < n; index++){
        // aage badhne se pahle purani window ka answer nikalo
        if(dq.empty()){
            cout<<"0"<<endl;
        }
        else{
            cout<<arr[dq.front()]<<" ";
        }
        // removal -> jo bhi index out of range hai, usko queue se remove kardo
        if(index - dq.front() >= k){
            dq.pop_front();
        }
        // addition
        if(arr[index] < 0){
            dq.push_back(index);
        }
    }
    // last window ka answer print kardo
    if(dq.empty()){
        cout<<"0"<<endl;
    }
    else{
        cout<<arr[dq.front()]<<" ";
    }
}

int main(){
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int n = 7; 
    int k = 3;
    printFirstNegative(arr, n, k);
    
    return 0;
}