// selection sort

#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& v){
    int n = v.size();
    for(int i=0; i<n-1; i++){
        // ith element is the smallest element
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        // swap ith and minIndex element
        swap(v[i], v[minIndex]);
    }
}

void print(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {3, 5, 1, 2, 7, 4, -1, 0};
    selectionSort(v);
    print(v);
    
    return 0;
}