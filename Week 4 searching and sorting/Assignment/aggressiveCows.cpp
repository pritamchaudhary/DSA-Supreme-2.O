// GFG -> Aggressive Cows

// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    bool isPossibleSolution(vector<int>& stalls, int k, int mid){
        int c = 1;
        int pos = stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - pos >= mid){
                c++;
                pos = stalls[i]; //one more cow has been placed
            }
            if(c == k){
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        
        int start = 0;
        int end = stalls[stalls.size()-1] - stalls[0];
        int ans = -1;
        
        while(start <= end){
            int mid = (start + end) >> 1;
            if(isPossibleSolution(stalls, k, mid)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};