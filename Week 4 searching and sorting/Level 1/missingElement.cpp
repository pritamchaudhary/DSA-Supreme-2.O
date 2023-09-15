// find missing element in sorted array

#include<iostream>
using namespace std;

int missingElement(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        int diff = arr[mid] - mid;

        if(diff == 1){
            s = mid + 1;
        }
        else{
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    if(ans + 1 == 0){
        return n+1;
    }
    
    return ans + 1;
}

int main(){
    int arr[8] = {1, 2, 3, 4, 5, 6, 7,8};
    int size = 8;

    int finalAns = missingElement(arr, size);
    cout<<"Missing element is: "<<finalAns<<endl;
    
    return 0;
}