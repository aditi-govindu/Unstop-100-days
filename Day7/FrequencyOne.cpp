/*
Description: Suman is a laborious college boy and he is very good at mathematics. He is doing his assignment of computer science but he is not able to solve one coding problem.This problem consists of an integer, N and Suman has to find out the total number of set bits in all numbers starting from 1 to N.

Suman needs your help in solving the problem.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int setBits(int m)
{
    int c = 0;
    while(m)
    {
        // Set bits in each number
        c += m & 1;
        m >>= 1;
    }
    return c;
}

int main() 
{
    // Count no. of set bits in range 1 to n
    int n, count = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        count += setBits(i);
    cout << count << endl;
    return 0;
}