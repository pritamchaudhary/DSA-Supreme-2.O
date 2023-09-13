// transpose of a matrix

#include<iostream>
using namespace std;

void transposeMatrix(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=i; j<col; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void printArray(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[4][4] = {
                    {1, 2, 3, 4},
                    {5, 6, 0, 8},
                    {9, 100, 1, 11},
                    {3, 5, 7, 2}
    };

    int row = 4;
    int col = 4;

    transposeMatrix(arr, row, col);
    printArray(arr, row, col);
    
    return 0;
}