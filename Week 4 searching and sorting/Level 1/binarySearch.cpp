// Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while(start <= end){
        // found
        if(arr[mid] == target){
            // return index of the found element
            return mid;
        }
        else if(arr[mid] < target){
            // go to right part
            start = mid + 1;
        }
        else if(arr[mid] > target){
            // go to left part
            end = mid - 1;
        }
        // mid update
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int target = 60;
    int ansIndex = binarySearch(arr, size, target);
    
    if(ansIndex == -1){
        cout<< "Element not found "<<endl;
    }
    else{
        cout<< "Element found at Index: "<<ansIndex<<endl;
    }
    
    return 0;
}