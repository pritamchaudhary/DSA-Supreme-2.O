// divide two numbers with precision

#include<iostream>
using namespace std;

int getQuotient(int dividend, int divisor){
    int start = 0;
    int end = dividend;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mid * divisor == dividend){
            return mid;
        }
        else if(mid * divisor < dividend){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

double myPrecision(int dividend, int divisor){
    double quotient = getQuotient(dividend, divisor);
    double step = 0.1;
    int precision = 5;
    for(int i=0; i<precision; i++){
        double j = quotient;
        while(j * divisor <= dividend){
            quotient = j;
            j += step;
        }
        step = step/10;
    }
    return quotient;
}

int main(){
    double dividend = 29;
    double divisor = -7;
    double ans = myPrecision(abs(dividend), abs(divisor));

    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
        ans = 0 - ans;
    }
    cout<<ans<<endl;

    
    return 0;
}