// find pivot element 

#include<iostream>
#include<vector>
using namespace std;

int findPivotElement(vector<int>& arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s <= e){
        // corner case
        if(s == e){
            // single element
            return s;
        }

        if(arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] < arr[mid-1]){
            return mid-1;
        }
        else if(arr[s] > arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> v;
    v.push_back(12);
    v.push_back(14);
    v.push_back(16);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);

    int pivotIndex = findPivotElement(v);
    cout<<"Pivot index is: "<<pivotIndex<<endl;
    
    return 0;
}