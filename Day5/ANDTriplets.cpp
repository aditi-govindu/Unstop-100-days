#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

/*
Description: Print the number of AND triples, given an integer array arr.

An AND triplet is a set of three indices i, j, and k such that:

0 <= i<arr.length
0 <= j <arr.length
0 <= k <arr.length
arr[i] &arr[j] &arr[k] == 0, where & represents the bitwise-AND operator.
*/

int main() 
{
    int n, temp, count = 0;
    cin >> n;
    vector<int> arr;

    // Accept array of elements
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                // Compute logical AND of 3 values
                int res = (arr[i] & arr[j]) & arr[k];
                if(res == 0)
                {
                    // Increment count whenever 0 is seen
                    count++;
                }
            }
        }
    }
    // Display final result
    cout << count << endl;
    return 0;
}