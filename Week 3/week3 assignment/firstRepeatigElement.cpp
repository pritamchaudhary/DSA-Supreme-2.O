// gfg -> First Repeating Element

// Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // for(int i=0; i<n; i++){
        //     bool isRepeated = false;
        //     for(int j=i+1; j<n; j++){
        //         if(arr[i] == arr[j]){
        //             isRepeated = true;
        //             return i+1;
        //         }
        //     }
        // }
        // return -1;
        
        
        // optimised solution
        
        unordered_map<int, int> hash;
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(hash[arr[i]] > 1){
                return i+1;
            }
        }
        return -1;
    }
};