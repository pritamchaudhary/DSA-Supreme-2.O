// gfg -> Common elements in 3 sorted array

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            set<int>st;
            int i, j, k;
            i=j=k=0;
            
            while(i<n1 && j<n2 && k<n3){
                if(A[i] == B[j] && B[j] == C[k]){
                    st.insert(A[i]);
                    i++, j++, k++;
                }
                else if(A[i] < B[j]){
                    i++;
                }
                else if(B[j] < C[k]){
                    j++;
                }
                else{
                    k++;
                }
            }
            for(auto i : st){
                ans.push_back(i);
            }
            return ans;
        }
};