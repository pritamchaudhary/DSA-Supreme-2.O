// leetcode 983. Minimum Cost For Tickets

// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

        // a 1-day pass is sold for costs[0] dollars,
        // a 7-day pass is sold for costs[1] dollars, and
        // a 30-day pass is sold for costs[2] dollars.
        // The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mincostTickets_helper(vector<int>& days, vector<int>& costs, int i){
        // base case
        if(i >= days.size()) return 0;
        // sol for a case
        // 1 day pass taken
        int cost1 = costs[0] + mincostTickets_helper(days, costs, i+1);

        // 7 days pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost7 = costs[1] + mincostTickets_helper(days, costs, j);

        // 30 days pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int cost30 = costs[2] + mincostTickets_helper(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTickets_helper(days, costs, 0);
    }
};