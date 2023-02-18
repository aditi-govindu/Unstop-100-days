#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: The employees of a warehouse maintain a record of items that were brought in and taken out of it each day. The items taken out are represented as negative integers, and items brought in are represented as non-negative integers. The employees noticed that some of the entries in today’s record had been repeated by mistake.

The record has been given as a sorted linked list, and the employees ask for your help to get a new sorted linked list containing only the unique entries in it.
*/

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> numbers;

    // Accept input from user
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    vector<int> :: iterator ip;
    // Store unique numbers in array
    ip = std::unique(numbers.begin(), numbers.end());
    // Resize array to remove undefined elements
    numbers.resize(std::distance(numbers.begin(), ip));
    // Display final results to user
    cout << numbers.size() << endl;
    for(ip = numbers.begin(); ip != numbers.end(); ++ip)
        cout << *ip << " ";
    return 0;
}