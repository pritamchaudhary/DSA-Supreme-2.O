// find maximum number in an array

#include <iostream>
#include <limits.h>
using namespace std;

int findMaximumNumber(int arr[], int size){
    int maxAns = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > maxAns){
            maxAns = arr[i];
        }
    }
    return maxAns;
}

int main(){
    int arr[5] = {12, 59, 50, 10, 100};
    int size = 5;

    int maximum = findMaximumNumber(arr, size);
    cout<< "Maximum number is: "<< maximum <<endl;
    
    return 0;
}