// leetcode 632. Smallest Range Covering Elements from K Lists

// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Info{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c){
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare{
public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        // process first k element
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info* temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()){
            Info* topNode = pq.top();
            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;
            pq.pop();

            mini = topNode->data;
            if((maxi-mini) < (ansEnd-ansStart)){
                ansStart = mini;
                ansEnd = maxi;
            }
            // insertion
            if(topCol + 1 < nums[topRow].size()){
                int newElement = nums[topRow][topCol + 1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol+1);
                pq.push(newInfo);
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};