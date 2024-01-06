// leetcode 509. Fibonacci Number

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

#include<iostream>
using namespace std;

class Solution {
public:
    int solveUsingTabulationSpaceOptimised(int n){
        int prev = 0;
        if(n == 0){
            return 0;
        }
        int curr = 1;
        if(n == 1){
            return 1;
        }
        int ans;       
        for(int i=2; i<=n; i++){
            ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
    int fib(int n) {
        int ans = solveUsingTabulationSpaceOptimised(n);
        return ans;
    }
};