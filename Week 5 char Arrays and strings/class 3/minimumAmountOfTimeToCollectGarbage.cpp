// leetcode 2391. Minimum Amount of Time to Collect Garbage

// You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

// You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

// There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

// Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

// Return the minimum number of minutes needed to pick up all the garbage.


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickG = 0;
        int pickM = 0;
        
        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        for(int i=0; i<garbage.size(); i++){
            string curr = garbage[i];
            for(int j=0; j<curr.length(); j++){
                char ch = curr[j];
                if(ch == 'P'){
                    pickP++;
                    lastP = i;
                }
                else if(ch == 'G'){
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'M'){
                    pickM++;
                    lastM = i;
                }
            }
        }
        // calculate travel time
        for(int i=0; i<lastP; i++){
            travelP += travel[i];
        }
        for(int i=0; i<lastG; i++){
            travelG += travel[i];
        }
        for(int i=0; i<lastM; i++){
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
    }
};