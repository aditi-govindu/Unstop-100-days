#include <bits/stdc++.h>
using namespace std;

/*
Description: For her birthday, Bob gifted Alice a rare 32-bit unsigned integer n. She now wants to pair it up with another 32-bit unsigned integer of her own. She wants to choose an integer m such that n⊙m = 0. Here, ⊙ represents the bitwise XNOR operation. Help Alice find the required unsigned integer to pair with n. It can be proved that there will always exist a 32-bit number that satisfies the given condition.
*/

int main()
{
    // read inputs
    uint32_t n;
    cin >> n;

    // declare result to be 0 initially
    uint32_t res = 0;

    //iterate through each bit of n
    for(int i = 0; i < 32; i++)
    {
        // integer with ith bit high = 2^i
        int pw = (1 << i);
        // if a bit is low, set that bit 
        // in the result as high
        if((n & pw) == 0)
            res |= pw;
    }
    cout << res << endl;
    return 0;
}