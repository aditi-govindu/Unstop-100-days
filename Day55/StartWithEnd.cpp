#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Alice gave Bob a Linked List of size n and asked him to find the maximum sum among the (first element + last element, second element + second last element, .........., (n/2 th element , n/2+1 th element ). 
You are given the head of the linked list. Your task is to find the maximum sum according to the given condition.
Note - n is always even.
*/

int main() 
{
    int n;
    cin >> n;
    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    int i = 0;
    // Set largest to -4999 as elements can be in the range of -5000 to 5000
    int max = -4999;

    while(i < n/2)
    {
        // Travel to middle of array, adding 2 numbers at a time
        if (max < numbers[i] + numbers[n - i - 1])
            max = numbers[i] + numbers[n - i -1];
        i++;
    }
    cout << max << endl;
    return 0;
}