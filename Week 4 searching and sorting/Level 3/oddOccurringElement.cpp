// find odd occurring element

#include<iostream>
using namespace std;

int findOddOccurringElement(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while(s <= e){
        // single element
        if(s == e){
            return s;
        }
        // mid check -> even or odd
        if(mid & 1){
            // mid & 1 -> true -> odd no.
            if(mid-1 >= 0 && arr[mid-1] == arr[mid]){
                // right me jao
                s = mid + 1;
            }
            else{
                // left me jao
                e = mid - 1;
            }
        }
        else{
            // even
            if(mid+1 < n && arr[mid] == arr[mid+1]){
                // right me jao
                s = mid+2;
            }
            else{
                e = mid;
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[] = {10, 10, 2, 2, 5, 5,2, 5, 5, 20, 20, 11, 11, 10, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int ansIndex = findOddOccurringElement(arr, size);

    cout<<"Final ans is: "<<arr[ansIndex]<<endl;
    
    return 0;
}