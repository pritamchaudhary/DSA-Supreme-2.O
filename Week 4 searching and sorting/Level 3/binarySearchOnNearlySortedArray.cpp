// binary search on nearly sorted array

#include<iostream>
using namespace std;

int searchOnNearlySortedArray(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e){
        if(mid >= 0 && arr[mid-1] == target){
            return mid-1;
        }
        if(arr[mid] == target){
            return mid;
        }
        if(mid+1 < n && arr[mid+1] == target){
            return mid + 1;
        }
        else if(target > arr[mid]){
            // right 
            s = mid + 2;
        }
        else{
            // left 
            e = mid - 2;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int size = sizeof(arr)/sizeof(int);
    int target = 30;

    int targetIndex =  searchOnNearlySortedArray(arr, size, target);

    if(targetIndex == -1){
        cout<< "Element not found "<< endl;
    }
    else{
        cout<< "Element found at index: "<<targetIndex<<endl;
    }
    
    return 0;
}