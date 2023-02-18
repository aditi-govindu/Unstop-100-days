#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description:  A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Display the number of indices where heights[i] != expected[i].
*/

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> numbers;
    vector<int> copy;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
        copy.push_back(temp);
    }

    sort(copy.begin(), copy.end());
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        // Compare numbers at sorted and original array
        if(copy[i] != numbers[i])
            count++;
    }
    cout << count << endl;
    return 0;
}