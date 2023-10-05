// GFG -> GCD of two numbers

// Given two positive integers A and B, find GCD of A and B.

#include<iostream>
using namespace std;

class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
        if(A == 0) return B;
        if(B == 0) return A;
        
        while(A > 0 && B > 0){
            if(A > B){
                A = A - B;
            }
            else{
                B = B - A;
            }
        }
	    return A == 0 ? B : A;
	} 
};