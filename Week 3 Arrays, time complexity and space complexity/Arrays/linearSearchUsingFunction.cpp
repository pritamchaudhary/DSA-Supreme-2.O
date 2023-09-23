#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            // found
            return true;
        }
    }
    // not found
    return false;
}

int main(){
    int arr[5] = {2, 5, 7, 3, 10};
    int n = 5;
    int target = 3;

    bool ans = linearSearch(arr, n, target);
    if(ans == 1){
        cout<< "target found"<< endl;
    }
    else{
        cout<< "target not found"<< endl;
    }
    
    return 0;
}