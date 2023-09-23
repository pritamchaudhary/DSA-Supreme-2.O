// shift array element by one

#include<iostream>
using namespace std;

void shiftElementByOne(int arr[], int n){
    int temp = arr[n-1];

    for(int i=n-1; i>=1; i--){
        arr[i] = arr[i-1];
    }

    arr[0] = temp;
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    shiftElementByOne(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}