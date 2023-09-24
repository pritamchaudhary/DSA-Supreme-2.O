// bubble sort

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& v){
    int n = v.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
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
    bubbleSort(v);
    print(v);
    
    return 0;
}