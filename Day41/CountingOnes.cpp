#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
Description: Given an integer N. Print an array in which each index i denotes the number of 1’s in the binary representation of i.
*/

// Function to count no. of 1's in given number
int binary(int n)
{
    int count = 0;
    while(n)
    {
        int digit = n%2;
        if(digit == 1)
            count++;
        n = n/2;
    }
    return count;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> ans(n+1);

    // Run loop to find count of 1's from 0 till n (inclusive)
    for(int i = 0; i <= n; i++)
        ans[i] = binary(i);
    // Display results to user
    for(int i = 0; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}s