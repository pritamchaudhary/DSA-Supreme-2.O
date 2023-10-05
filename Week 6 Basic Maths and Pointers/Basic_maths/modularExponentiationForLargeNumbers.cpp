// GFG -> Modular Exponentiation for large numbers

// Implement pow(x, n) % M.
    // In other words, given x, n and M, find (xn) % M.

#include <iostream>
using namespace std;

class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        long long int ans = 1;
        while (n > 0)
        {
            //  if n is odd
            if (n & 1)
            {
                ans = (ans * x) % M;
            }
            x = (x * x) % M;
            n >>= 1;
        }
        return ans % M;
    }
};