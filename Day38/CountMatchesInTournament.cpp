#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: You are given an integer n, the number of teams in a tournament that has strange rules:
If the current number of teams is even, each team gets paired with another team. A total of n / 2 matches are played, and n / 2 teams advance to the next round.
If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2matches are played, and (n - 1) / 2 + 1 teams advance to the next round.
Return the number of matches played in the tournament until a winner is decided.
*/

int main() 
{
    int n;
    cin >> n;

    int total = 0;

    // Keep playing till 1 team is left
    while(n > 1)
    {
        // If teams are even, n/2 advance to next stage
        if(n%2 == 0)
        {
            total += n/2;
            n = n/2;
        }
        // If teams are odd, (n-1 / 2) + 1 move to next stage
        else
        {
            total += (n-1) / 2;
            n = ((n-1) / 2) + 1;
        }
    }
    // Show final matches played
    cout << total << endl;
    return 0;
}