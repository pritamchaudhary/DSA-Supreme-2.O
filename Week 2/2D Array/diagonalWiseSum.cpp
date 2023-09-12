// diagonal wise sum 

#include<iostream>
using namespace std;

void diagonalWiseSum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i=0; i<row; i++){ 
        sum = sum + arr[i][i];
    }

    for(int i=0; i<row; i++){
        cout<<arr[i][i];
    }
}

int main(){
    int arr[4][4] = {
                    {1, 2, 3, 4},
                    {5, 6, 0, 8},
                    {9, 100, 1, 11},
                    {3, 2, 1, 5}
    };

    int row = 4;
    int col = 4;

    diagonalWiseSum(arr, row, col);
    
    return 0;
}