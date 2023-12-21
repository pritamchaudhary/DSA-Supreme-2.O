// find kth smallest element

#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k){
    priority_queue<int> pq;
    // process first k element 
    for(int i=0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }
    // remaining element ko tabhi push karenge jab wo root se chhote honge
    for(int i=k; i<n; i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

int main(){
    int arr[] = {3, 5, 4, 6, 9, 8, 7};
    int n = 7; 
    int k = 4;
    cout<<"4th smallest element: "<<getKthSmallestElement(arr, n, k)<<endl;
    
    return 0;
}