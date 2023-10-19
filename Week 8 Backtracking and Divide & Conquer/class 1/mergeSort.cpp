// merge sort using recursion

#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s + e)/2;
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    // create left and right array
    int* left = new int[lenLeft];
    int* right = new int[lenRight];

    // copy values from original array to left array
    int k = s;
    // k -> starting index of left array values in original array
    for(int i=0; i<lenLeft; i++){
        left[i] = arr[k];
        k++;
    }
    // copy values from original array to right array
    k = mid + 1;
    for(int i=0; i<lenRight; i++){
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    // left array is already sorted
    // right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    // 2 more case
    // 1st case -> left array exhaust but right array me element abhi bhi bache hai
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    // 2nd case -> right array exhaust but left array me element abhi bhi bache hai
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    // 1 more steps pending
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e){
    // base case
    if(s > e){
        // invalid array
        return;
    }
    if(s == e){
        // single element
        return;
    }
    // break the array
    int mid = (s + e)/2;

    // s -> mid -> left
    // mid + 1 -> e -> right
    // recursion call
    // left and right array ko sort karwana hai

    // recursive call for left array
    mergeSort(arr, s, mid);

    // recursive call for right array
    mergeSort(arr, mid + 1, e);

    // merge 2 sorte array
    merge(arr, s, e);
}

int main(){
    int arr[] = {2, 1, 6, 9, 4, 5};
    int size = 6;
    int s = 0;
    int e = size - 1;

    cout<<"Before merge sort: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr, s, e);

    cout<<"After merge sort: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}