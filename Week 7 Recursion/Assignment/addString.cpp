// leetcode 415. Add Strings

// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

#include<iostream>
using namespace std;

class Solution {
public:
    void addRE(string& num1, int p1, string& num2, int p2, int carry, string& ans){
        // base case
        if(p1 < 0 && p2 < 0){
            if(carry != 0){
                ans.push_back(carry + '0');
            }
            return;
        }
        // one case solve
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum / 10;
        ans.push_back(digit + '0');

        // recursive call
        addRE(num1, p1-1, num2, p2-1, carry, ans);
    }

    string addStrings(string num1, string num2) {
        string ans = "";
        addRE(num1, num1.size()-1, num2, num2.size()-1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};