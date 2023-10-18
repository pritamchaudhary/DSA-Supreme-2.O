// leetcode 279. Perfect Squares

// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// TLE

#include<iostream>
using namespace std;

class Solution {
public:
    int numSquareHelper(int n){
        // base case
        if(n == 0) return 1;
        if(n < 0) return 0;
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
            if(numberOfPerfectSquares < ans){
                ans = numberOfPerfectSquares;
            }
            i++;
        }
        return ans;
    }

    int numSquares(int n) {
        return numSquareHelper(n) - 1;
    }
};