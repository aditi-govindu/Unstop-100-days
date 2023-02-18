/*
Description: Ram had an array of integers .He wants to know whether he can make an arithmetic progression using this sequence or not?

Note: You have to include all elements .

Numbers present in the array are unsorted.

Help Ram in finding whether he can make an arithmetic progression using sequence or not?

Return true if he can make a sequence using this else false.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool APCheck(vector<int>& differences)
{
    // If any common difference is not equal to its next value, return false
    for(int i = 0; i < differences.size() - 1; i++)
    {
        if(differences[i] != differences[i + 1])
            return false;
    }
    return true;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> numbers;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());

    vector<int>differences;

    for(int i = 0; i < n - 1; i++)
        differences.push_back(numbers[i + 1] - numbers[i]);

    if(APCheck(differences))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}