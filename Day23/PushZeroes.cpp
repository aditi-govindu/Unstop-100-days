#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: You are given an array, containing numbers and zeroes, you need to push all the zeroes to the end of the array. Notice that while pushing the zeroes the relative ordering between the non-zero elements should not change.

Given an array, push the zeroes and print the array.
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    int temp;
    int zeroes = 0;
    
    cin >> n;
    vector<int> numbers;

    for(int i = 0; i < n; i++)
    {
        // Count no. of zeroes in input
        cin >> temp;
        if(temp == 0)
            zeroes++;
        // Append non zero as it is to array
        else
            numbers.push_back(temp);
    } 
    // Append zeroes to end of array
    for(int z = 0; z < zeroes; z++)
        numbers.push_back(0);
    
    // Display final result
    for(int i = 0; i < n; i++)
        cout << numbers[i] << " ";
    return 0;
}