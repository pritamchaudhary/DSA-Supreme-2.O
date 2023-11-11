// leetcode 526. Beautiful Arrangement

// Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

        // perm[i] is divisible by i.
        // i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void countArrangementHelper(vector<int>& v, int n, int& ans, int currNum){
        // base case
        if(currNum == n+1){
            ans++;
            return;
        }
        for(int i=1; i<=n; i++){
            if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
                v[i] = currNum;
                countArrangementHelper(v, n, ans, currNum+1);
                // backtrack
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans = 0;
        countArrangementHelper(v, n, ans, 1);
        return ans;
    }
};