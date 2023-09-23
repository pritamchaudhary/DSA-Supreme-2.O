// reverse an array

#include<iostream>
using namespace std;

void reverseArray(int arr[], int size){

    // using for loop
    // for(int left=0, right = size-1; left<=right; left++, right--){
    //     swap(arr[left], arr[right]);
    // }

    // using while loop
    int left = 0;
    int right = size-1;

    while(left <= right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    // printing the array
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    reverseArray(arr, size);
    
    return 0;
}