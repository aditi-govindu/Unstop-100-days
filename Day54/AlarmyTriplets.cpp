/*
Description: Ram was playing with arrays and was practicing problems based on arrays when he 
got stuck in a problem, he asked you for help.
A given array is said to be nice if it contains at least 1 Alarmy triplet in it. 
An array nums contains an Alarmy triplet if it there exists a triple of indices (i, j, k) 
such that i< j < k and nums[i] <nums[j] <nums[k].
Given an array tell whether it’s a nice array or not.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define INT_MAX 1e9 + 1;

int Alarmy(vector<int> arr, int n)
{
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        // If current less than 1st minimum
        if(arr[i] <= min1)
            min1 = arr[i];
        // If current less than 2nd minimum
        else if(arr[i] <= min2)
            min2 = arr[i];
        // All 3 minimum found
        else
            return 1;  
    }
    return 0;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> num(n);

    for(int i = 0; i < n; i++)
        cin >> num[i];

    // Found triplet, display result
    if(Alarmy(num, n) == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}