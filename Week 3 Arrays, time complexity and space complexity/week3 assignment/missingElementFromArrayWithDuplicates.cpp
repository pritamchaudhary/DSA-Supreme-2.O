// missing elements from an array with duplicates

#include<iostream>
using namespace std;

void missingElement(int arr[], int n){

    // visited method
    for(int i=0; i<n; i++){
        int index = abs(arr[i]);
        if(arr[index - 1] > 0){
            arr[index-1] *= -1;
        }
    }

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // all positive index are missing 

    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            cout<<i+1<<" ";
        }
    }
}


void sortingSwappingMethod(int arr[], int n){
    int i=0;
    while(i < n){
        int index = arr[i] - 1;
        if(arr[i] != arr[index]){
            swap(arr[i], arr[index]);
        }
        else{
            i++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            cout<< i+1<<" ";
        }
    }
    cout<<endl;
}


int main(){
    int arr[] = {1, 3, 5, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    // missingElement(arr, n);

    sortingSwappingMethod(arr, n);
    
    return 0;
}