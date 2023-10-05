// slow exponentiation

#include<iostream>
using namespace std;

int slowExponentiation(int a, int b){
    int ans = 1;
    for(int i=0; i<b; i++){
        ans = ans * a;
    }
    return ans;
}

int main(){
    int a = 5, b = 3;
    int ans = slowExponentiation(a, b);
    cout<<ans<<endl;
    
    return 0;
}