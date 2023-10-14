#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int target){
    // base case
    if(s > e){
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] < target){
        return binarySearch(arr, mid+1, e, target);
    }
    else{
        return binarySearch(arr, s, mid-1, target);
    }

}

int main(){
    int arr[] = {20, 30, 50, 59, 60, 65};
    int size = 6;
    int start = 0;
    int end = size-1;
    int target = 59;

    int foundIndex = binarySearch(arr, start, end, target);
    if(foundIndex != -1){
        cout<<"target found at index: "<<foundIndex<<endl;
    }
    else{
        cout<<"target not found"<<endl;
    }
    
    return 0;
}