#include<iostream>
using namespace std;

int main(){
    int arr[3] = {10, 20, 30};
    int n = 3;

    int sum1 = 0, sum2=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum1 = sum1 + arr[i];
            sum2 = sum2 + arr[j];
            
            cout<<sum1 <<", "<<sum2<<endl;
            
        }
    }
}