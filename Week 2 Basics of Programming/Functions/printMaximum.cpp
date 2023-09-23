#include<iostream>
using namespace std;

// void printMaximum(int num1, int num2, int num3){
//     if(num1 >= num2 && num1 >= num3){
//         cout<<"Maximum is: "<< num1<< endl;
//     }
//     else if(num2 >= num1 && num2 >= num3){
//         cout << "Maximum is: "<< num2 << endl;
//     }
//     else{
//         cout<< "Maximum is: "<< num3 << endl;
//     }
// }

// void printMaximum(int num1, int num2, int num3){
//     int ans1 = max(num1, num2);
//     int finalAns = max(ans1, num3);
//     cout<< "Maximum is: "<< finalAns << endl;
// }

int printMaximum(int num1, int num2, int num3){
    int ans1 = max(num1, num2);
    int finalAns = max(ans1, num3);
    return finalAns;
}

int main(){
    int ans = printMaximum(56, 77, 89);
    cout<< "Maximum is: "<< ans<< endl;
}

// int main(){
//     printMaximum(56, 56, 56);
    
//     return 0;
// }

