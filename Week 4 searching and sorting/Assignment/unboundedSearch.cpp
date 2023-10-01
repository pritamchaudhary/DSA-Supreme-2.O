// unbounded search

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
    int i = 0;
    int j = 1;
    while(arr[j] < x){
        i = j;
        j = j*2;
    }
    return binarySearch(arr, i, j, x);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 56, 70};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 13;
    int ans = exponentialSearch(arr, n, x);
    cout<< ans<<endl;
    
    return 0;
}