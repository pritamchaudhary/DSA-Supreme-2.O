// leetcode 1155. Number of Dice Rolls With Target Sum

// You have n dice, and each die has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

// output -> TLE, later i will solve this question using DP

#include<iostream>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // base case
        if(target < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n == 0 && target != 0) return 0;
        if(n != 0 && target == 0) return 0;

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = ans + numRollsToTarget(n-1, k, target-i);
        }
        return ans;
    }
};