#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Given an integer array nums, return an array answer such that answer[i] isequal to the product of allthe elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

int main() 
{
    int n;
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    for(int i = 0; i < n; i++)
    {
        int prod = 1;
        for(int j = 0; j < n; j++)
        {
            // Index not equal, store product
            if(i != j)
                prod = prod * numbers[j];
        }
        // Display result to user
        cout << prod << endl;
    }
    return 0;
}