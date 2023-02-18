/*
Description: James has two binary strings, ‘a’ and ‘b’. He asked Jimmy to find the sum of the number of positions at which the corresponding bits are different between a and all contiguous substrings of b of length of a. Help Jimmy to find the total sum.

Example - 01 and 00111 -> there are four contiguous substrings of b of length |a|: "00", "01", "11", and "11". The distance between "01" and "00" is |0 - 0| + |1 - 0| = 1. The distance between "01" and "01" is |0 - 0| + |1 - 1| = 0. The distance between "01" and "11" is |0 - 1| + |1 - 1| = 1. Last distance counts twice, as there are two occurrences of string "11". The sum of these edit distances is 1 + 0 + 1 + 1 = 3.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 200002
 
int main() 
{
    string a , b; 
    cin >> a >> b; 
    long long int i, len1 = a.size(), len2 = b.size(), ones = 0, sum = 0;
    long long int diff = len2-len1+1;
    // Count no. of ones in b
    for (i=0; i<diff; i++) 
    {
        if (b[i] == '1') 
            ones++;
    }
    for (i=0; i<len1; i++) 
    {
        // If a has 0, add ones to final sum
        if (a[i] == '0') 
            sum += ones;
        // Else, add sum as different - ones
        else 
            sum += (diff-ones);
        if (i == len1-1) break;
        if (b[i] == '1') ones--;
        if (b[i+diff] == '1') ones++;
    }
    // Display final result
    cout << sum; 
    return 0;
}