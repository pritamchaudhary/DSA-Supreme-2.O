// gfg -> Key Pair

// Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	
	
// 	method 1
	
// 	bool twoSum(int arr[], int n, int x){
// 	    for(int i=0; i<n; ++i){
// 	        for(int j=i+1; j<n; j++){
// 	            if(arr[i] + arr[j] == x){
// 	                return true;
// 	            }
// 	        }
// 	    }
// 	    return false;
// 	}


// method 2 Two pointer approach

    bool twoSumTwoPointerApproach(int arr[], int n, int x){
        int low = 0;
        int high = n - 1;
        while(low < high){
            int currSum = arr[low] + arr[high];
            if(currSum == x){
                return true;
            }
            // if currSum is greate than x, it means current pair is two large
            // we have to move the high index to left to consider the smaller pair
            else if(currSum > x){
                high--;
            }
            
            // if currSum is less than x, it means current pair is two small
            // we have to move the low index to right to consider the larger pair
            else{
                low++;
            }
        }
        return false;
    }
	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	   // bool ans = twoSum(arr, n, x);
	   // return ans;
	   
	   sort(arr, arr+n);
	   return twoSumTwoPointerApproach(arr, n, x);
	}
};