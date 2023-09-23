// extreme print in an array

#include<iostream>
using namespace std;

void extremePrint(int arr[], int size){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        if(arr[left] == arr[right]){
            cout<< arr[left] << endl;
        }
        else{
            cout<< arr[left]<<" ";
            cout<< arr[right] << " ";
        }
        left++;
        right--;
    }
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    extremePrint(arr, size);
    
    return 0;
}