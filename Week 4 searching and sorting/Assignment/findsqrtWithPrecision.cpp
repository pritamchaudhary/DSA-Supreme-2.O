// find square root with precision

#include<iostream>
using namespace std;

int mysqrt(int n){
    int start = 0;
    int end = n;
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(mid * mid <= n){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

double myPrecisionSqrt(int n){
    double sqrt = mysqrt(n);
    double step = 0.1;
    int precision = 10;
    for(int i=0; i<precision; i++){
        double j = sqrt;
        while(j * j <= n){
            sqrt = j;
            j += step;
        }
        step = step/10;
    }
    return sqrt;
}

int main(int argc, const char * argv[]){
    int n = 51;
    double sqrt = myPrecisionSqrt(n);
    // cout<<sqrt<<endl;
    printf("%0.10f", sqrt);
    
    return 0;
}