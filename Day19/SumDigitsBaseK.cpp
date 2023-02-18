#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Given an integer n (in base 10) and a base k, return the sum of the digits of n after converting n from base 10 to base k.

After converting, each digit should be interpreted as a base 10 number, and the sum should be returnedin base 10.
*/

int convertBase(int num, int k)
{
    int converted = 0;

    // Get digits using modulus wrt base k
    while(num > 0)
    {
        int digit = num % k;
        // Add digits obtained
        converted += digit;
        num = num/k;
    }
    return converted;
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int base;
    cin >> n;
    cin >> base;

    cout << convertBase(n, base);
    return 0;
}