#include<iostream>
using namespace std;

int main(){
    int arr[3] = {10, 20, 30};
    int n = 3;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< arr[i] <<",";
            cout<< arr[j] <<endl;
        }
    }
    
    return 0;
}