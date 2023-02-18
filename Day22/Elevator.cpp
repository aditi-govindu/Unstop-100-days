#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Eve is in an elevator on the Nth floor. This elevator is a special type of elevator that has only two buttons. One to reach (N-1)th floor and another to (N/2)th floor. She wants to reach the ground floor i.e. the 0 th floor.

Help her to reach the ground floor by pressing buttons a minimum number of times.
*/

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    int count = 0;

    while(n)
    {
        // Divide by 2 for an even floor
        if(n%2 == 0)
            n = n/2;
        // Go 1 floor down for odd
        else
            n = n-1;
        // Every floor down is counted till n = 0
        count++;
    }
    cout << count << endl;
    return 0;
}