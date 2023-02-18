#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
Description: Write an algorithm to determine if a number n is good.

A good number is a number defined by the following process:

Break the number in its digits then replace the number by the sum of its digits.
Repeat this process until the number reaches 1 or the process loops endlessly in a cycle which does not contain 1.
Those numbers for which this process ends in 1 are good.
Return true if n is a good number, and false if otherwise.
*/

int SumSquare(int num)
    {
        // Calculate sum of square of digits
        int sum = 0;
        while(num > 0)
        {
            int digit = num % 10;
            sum += pow(digit, 2);
            num = num / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) 
    {
        unordered_map<int, int> seen(0);
        
        while(true)
        {
            // If n is 1, return true
            n = SumSquare(n);
            if(n == 1)
                return true;
            // Cycle detected, set hash value to 1
            if(seen[n] == 1)
                break;
            else
                seen[n] = 1;
        }
        if(n == 1)
            return true;
        return false;
    }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    if(isHappy(n) == 1)
        cout << "true" << endl; 
    else
        cout << "false" << endl;
    return 0;
}