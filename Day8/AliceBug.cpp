/*
Description: Alice is a software developer, and she recently faced a bug that showed up weirdly. The bug constantly shows up a stream of numbers on her computer. The stream of numbers consists of zero and non-zero values. The only solution to this bug is to adjust the array so that all zeros move in the end and non-zero values come at the start. Here’s a catch: the relative ordering of the elements should be the same after modifying that stream. Can You Help Alice in resolving the bug??
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> nonZero;
    int zero = 0;

    for(int i = 0; i < n; i++)
    {
        // Store non zero values as they come
        int temp;
        cin >> temp;
        if(temp != 0)
            nonZero.push_back(temp);
        // Increment count of 0
        else
            zero++;
    }
    // Display results as nonZeros followed by 0
    for(int i = 0; i < nonZero.size(); i++)
        cout << nonZero[i] << " ";
    for(int i = 0; i < zero; i++)
        cout << 0 << " ";
    cout << endl;
    return 0;
}