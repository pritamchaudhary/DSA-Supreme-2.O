// GFG -> The Painter's Partition Problem-II

// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

#include<iostream>
using namespace std;

class Solution
{
  public:
  
    bool isPossibleSolution(int a[], int n, int k, long long mid){
        long long timeSum = 0;
        int c = 1;
        for(int i=0; i<n; i++){
            if(a[i] > mid){
                return false;
            }
            if(a[i] + timeSum > mid){
                c++;
                timeSum = a[i];
                if(c > k){
                    return false;
                }
            }
            else{
                timeSum += a[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        long long start = 0;
        long long end = 0;
        for(int i=0; i<n; i++){
            end = end + arr[i];
        }
        
        long long ans = -1;
        while(start <= end){
            long long mid = start + (end-start)/2;
            if(isPossibleSolution(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};