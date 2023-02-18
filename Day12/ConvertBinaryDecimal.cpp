#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>

using namespace std;

/*
Description: Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
*/
int main() 
{
    int n;
    cin >> n;
    int temp;
    int decimal = 0;
    int power = n - 1;

    for(int i = 0; i < n; i++)
    {
        // Accept digit and multiply by power of 2
        cin >> temp;
        decimal += temp * pow(2.0, power--);
    }  
    cout << decimal << endl;
    return 0;
}