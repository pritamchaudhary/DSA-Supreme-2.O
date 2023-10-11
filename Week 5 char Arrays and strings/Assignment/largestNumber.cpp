// leetcode 179. Largest Number

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool myComp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1 > t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n : nums){
            snums.push_back(to_string(n));
        }

        sort(snums.begin(), snums.end(), myComp);
        
        if(snums[0] == "0"){
            return "0";
        }      
        string ans="";
        for(auto str: snums){
            ans = ans + str;
        }
        return ans;
    }
};