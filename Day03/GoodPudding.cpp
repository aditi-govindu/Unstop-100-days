#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Bob is going on a trip to Japan, where he finds a big pudding shop, where he sees a menu and food challenges. Bob accepts the challenge, so here are the game rules.

Pudding assigns an integer number to it. Bob has configured 

The good pudding.

Good pudding means the associated number has been reversed twice.  

Note:- For example, reversing 2022 gives 2202. Reversing 42100 offers 421 as the leading zeros are not retained.
*/

// Enter your code here. Read input from STDIN. Print output to STDOUT

bool reverse(int number)
{
    if(number != 0 && number%10 == 0)
        return 0;
    return 1;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        long long int num;
        cin >> num;

        bool ans = reverse(num);
        cout << ans << endl;
    }
    return 0;
}
