// find total occurrence in the sorted array

#include<iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int target){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(arr[mid] == target){
            // ans store
            ans = mid;
            // go to left part
            e = mid - 1;
        }
        else if(arr[mid] < target){
            // go to right part
            s = mid + 1;
        }
        else{
            // go to left part
            e = mid - 1;
        }
        // mid update
        mid = s + (e-s)/2;
    }
    return ans;
}

int findlastOccurrence(int arr[], int n, int target){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(arr[mid] == target){
            // ans store
            ans = mid;
            // go to right part
            s = mid + 1;
        }
        else if(arr[mid] < target){
            // go to right part
            s = mid + 1;
        }
        else{
            // go to left part
            e = mid - 1;
        }
        // mid update
        mid = s + (e-s)/2;
    }
    return ans;
}

int totalOccurrence(int arr[], int n, int target){
    int firstOcc = findFirstOccurrence(arr, n, target);
    int lastOcc = findlastOccurrence(arr, n, target);

    int totalOcc = lastOcc - firstOcc + 1;
    return totalOcc;
}

int main(){
    int arr[8] = {10, 20, 30, 30, 30, 30, 40, 50};
    int target = 30;
    int size = 8;

    int ans = totalOccurrence(arr, size, target);
    cout<< "Total occurrence is: "<<ans <<endl;

    return 0;
}