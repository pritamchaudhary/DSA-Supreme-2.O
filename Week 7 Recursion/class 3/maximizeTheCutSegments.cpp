// GFG -> Maximize The Cut Segments

// Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

// Note: if no segment can be cut then return 0.

#include<iostream>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;
        
        // I have cut 1 segment of x length
        int option1 = 1 + maximizeTheCuts(n-x, x, y, z);
        
        // cut 1 segment of y length
        int option2 = 1 + maximizeTheCuts(n-y, x, y, z);
        
        // cut 1 segment of z length
        int option3 = 1 + maximizeTheCuts(n-z, x, y, z);
        
        int finalAns = max(option1, max(option2, option3));
        
        return finalAns;
    }
};