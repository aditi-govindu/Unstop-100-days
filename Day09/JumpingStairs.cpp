#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Description: You are jumping a staircase. It takes n steps to reach the top.

Each time you can either jump 1 or 2 steps. Print in how many distinct ways can you jump to the top?
*/

int Fibonacci(int n)
{
    // Steps taken are in the form of Fibonacci series
    if(n <= 0)
        return 0;
    if(n == 1 || n == 2)
        return n;
    return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    cout << Fibonacci(n);
    return 0;
}