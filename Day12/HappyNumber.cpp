#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Mohit give a number to ram and tell to create an algorithm to determine if n is a happy number.

 

A happy number is one that can be calculated using the following formula:

* Start with any positive integer and replace it with the sum of its digits' squares.
* Repeat the process until the number equals 1 (where it will remain) or until it loops endlessly in a cycle that excludes 1.
* The numbers that end in 1 in this process are happy.
* If n is a happy number, return true; otherwise, return false.

Help Ram solve this problem
*/

int sumSquares(int n)
{
    // Separate digits and add squares
    int total = 0;
    while(n)
    {
        int digit = n % 10;
        total =  total + (digit * digit);
        n = (int)(n/10);
    }
    return total;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num;
    cin >> num;
    int result = sumSquares(num);

    // If number has exactly 1 digit, before decimal it will have 0. Stop process
    while( (int)(result/10) )  
        result = sumSquares(result);
    
    // If result is a single digit, check if it is 1
    if(result == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}