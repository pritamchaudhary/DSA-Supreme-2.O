// print reverse counting from n to 1

#include<iostream>
using namespace std;

void reverseCounting(int n){
    // base case
    if(n == 1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    reverseCounting(n-1);
}

int main(){
    reverseCounting(10);
    
    return 0;
}