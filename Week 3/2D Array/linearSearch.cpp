// Linear search in 2D array

#include<iostream>
using namespace std;

bool findTarget(int arr[][4], int row, int col, int target){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == target){
                // if found , return true;
                return true;
            }
        }
    }
    return false; 
}

int main(){
    int arr[3][4] = {
                    {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 1, 11}
    };

    int row = 3;
    int col = 4;
    int target = 11;
    cout<< "Found or Not: "<<findTarget(arr, row, col, target) <<endl;
    
    return 0;
}