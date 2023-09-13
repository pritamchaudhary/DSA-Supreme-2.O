// diagonal wise sum 

#include<iostream>
using namespace std;

void diagonalWiseSum(int arr[][4], int row, int col){
    int sum_major = 0;
    int sum_minor = 0;
    for(int i=0; i<row; i++){ 
        for(int j=0; j<col; j++){
            if(i == j){
                sum_major = sum_major + arr[i][j];
            }
            if((i+j) == col-1){
                sum_minor = sum_minor + arr[i][j];
            }
        }
    }
    cout<<"The sum of the major diagonal: "<<sum_major<<endl;
    cout<<"The sum of the minor diagonal: "<<sum_minor<<endl;
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