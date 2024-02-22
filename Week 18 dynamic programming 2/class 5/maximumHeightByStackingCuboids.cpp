// leetcode 1691. Maximum Height by Stacking Cuboids

// Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

// Return the maximum height of the stacked cuboids.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev){
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
            return true;
        }
        else{
            return false;
        }
    }

    int solveUsingTabulationSO(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        for(int curr_index=n-1; curr_index>=0; curr_index--){
            for(int prev_index=curr_index-1; prev_index>=-1; prev_index--){
                int include = 0;
                if(prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index])){
                    int heightToAdd = cuboids[curr_index][2];
                    include = heightToAdd + nextRow[curr_index+1];
                }
                int exclude = 0 + nextRow[prev_index+1];
                currRow[prev_index+1] = max(include, exclude);
            }
            // shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTabulationSO(cuboids);
        return ans;
    }
};