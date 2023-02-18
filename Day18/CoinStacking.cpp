#include <bits/stdc++.h>
using namespace std;

/*
Description: Krutin have n coins and want to make a staircase out of them. The stairwell is made up of k rows, each with exactly I coins. The stairwell's last row could be missing.

You as a BF of his you help him out ot return the number of full rows of the staircase you will create, given the integer n.
*/

int stackcoin(int n)
{
    long left = 0, right = n;
    long k, curr;
    // Binary search on m*n = required number
    while (left <= right) 
    {
        k = left + (right - left) / 2;
        curr = k * (k + 1) / 2;

        if (curr == n) 
            return (int)k;

        if (n < curr) 
            right = k - 1;
        else
            left = k + 1;
    }
    return (int)right;
}

int main() 
{     
    int n;
    cin>>n;

    int ans=stackcoin(n);
    cout<<ans<<endl;
}