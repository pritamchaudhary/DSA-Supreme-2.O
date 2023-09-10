#include<iostream>
using namespace std;

int main(){
    int arr[5] = {2, 6, 9, 12, 10};
    // int arr[10] = {1, 2, 5, 3, 4, 6, 9, 10, 8, 5};
    int target;
    cin>>target;
    int n = 10;
    bool flag = 0;

    for(int i = 0; i<5; i++){
        if(arr[i] == target){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout<< "target found"<< endl;
    }
    else{
        cout<< "target not found"<< endl;
    }
    
    return 0;
}