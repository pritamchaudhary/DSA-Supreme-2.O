// exponential search and unbounded binary search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int x){
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x){
    if(arr[0] == x){
        return 0;
    }
    int i=1;
    while(i<n && arr[i]<=x){
        i = i*2;
    }
    return binarySearch(arr, i/2, min(i, n-1), x);
}

int main(){
    int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 13;
    int ans = exponentialSearch(arr, n, x);
    cout<< ans<<endl;
    
    return 0;
}