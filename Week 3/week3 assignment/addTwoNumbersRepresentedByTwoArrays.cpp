// gfg -> Add two numbers represented by two arrays

// Given two array A[0….N-1] and B[0….M-1] of size N and M respectively, representing two numbers such that every element of arrays represent a digit. For example, A[] = { 1, 2, 3} and B[] = { 2, 1, 4 } represent 123 and 214 respectively. The task is to find the sum of both the numbers.

#include<iostream>
using namespace std;

class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        int carry = 0;
        string ans;
        int i = n-1;
        int j = m-1;
        while(i>=0 && j>=0){
            int x = a[i] + b[j] + carry;
            int digit = x%10;
            ans.push_back(digit + '0');
            carry = x/10;
            i--, j--;
        }
        
        while(i>=0){
            int x = a[i] + 0 + carry;
            int digit = x%10;
            ans.push_back(digit + '0');
            carry = x/10;
            i--;
        }
        
        while(j>=0){
            int x = 0 + b[j] + carry;
            int digit = x%10;
            ans.push_back(digit + '0');
            carry = x/10;
            j--;
        }
        
        if(carry){
            ans.push_back(carry + '0');
        }
        
        while(ans[ans.size()-1] == '0'){
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};