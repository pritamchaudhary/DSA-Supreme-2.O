// find minimum number in an array

#include<iostream>
#include<limits.h>
using namespace std;

int minNumber(int arr[], int size){
    int minAns = INT_MAX;
    for(int i=0; i<size; i++){
        if(arr[i] < minAns){
            minAns = arr[i];
        }
    }
    return minAns;
}

int main(){
    int arr[] = {23, 5, 34, 2, 1, 24};
    int size = 6;
    int finalAns = minNumber(arr, size);
    cout<< "Minimum Number: "<< finalAns<< endl;
    
    return 0;
}