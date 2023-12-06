// 134. Gas Station

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique..

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        // start from where we are starting the movement
        int start = 0;
        for(int i=0; i<gas.size(); i++){
            balance = balance + gas[i] - cost[i];
            if(balance < 0){
                deficit += abs(balance);
                start = i+1;
                balance = 0;
            }
        }
        if(balance - deficit >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};