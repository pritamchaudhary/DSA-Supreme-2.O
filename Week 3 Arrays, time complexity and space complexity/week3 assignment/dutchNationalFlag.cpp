// dutch national flag 
// move all negative number to the left side of an array

#include<iostream>
using namespace std;

void moveNegativeNumberToLeft(int arr[], int n){
    int low = 0;
    int high = n-1;
    while(low < high){
        if(arr[low] < 0){
            low++;
        }
        else if(arr[high] > 0){
            high--;
        }
        else{
            swap(arr[low], arr[high]);
        }
    }
}

int main(){
    int arr[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(arr)/sizeof(int);

    moveNegativeNumberToLeft(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}