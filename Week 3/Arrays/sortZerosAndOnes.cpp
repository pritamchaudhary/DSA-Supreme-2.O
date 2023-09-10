// sort 0's and 1's

#include<iostream>
using namespace std;

void sortZeroOne(int arr[], int n){
    int zeroCount = 0;
    int oneCount = 0;

    // counting all zero and one
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            zeroCount++;
        }
        if(arr[i] == 1){
            oneCount++;
        }
    }

    // place all zero first
    // int i;
    // for(i=0; i<zeroCount; i++){
    //     arr[i] = 0;
    // }

    // // place all ones
    // for(int j=i; j<n; j++){
    //     arr[j] = 1;
    // }


    // Easy way
    int index = 0;
    while(zeroCount--){
        arr[index] = 0;
        index++;
    }

    while(oneCount--){
        arr[index] = 1;
        index++;
    }
}

int main(){
    int arr[14] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0};
    int n = 14;

    sortZeroOne(arr, n);

    for(int i=0; i<n; i++){
        cout<< arr[i]<< " ";
    }
    cout<<endl;
    
    return 0;
}