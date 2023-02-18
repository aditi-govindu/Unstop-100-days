/*
Description: City biker is on his way on a road trip. The road trip is made up of n + 1 points at various altitudes. The biker begins his journey at point 0 with an altitude of 0 metres.

For all  (0 <= I < n), you are given an integer array gain of length n, where gain[i] is the net gain in altitude between points i and i+ 1. Return a point's highest altitude.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a;

    vector<int>gain;
    for(int i = 0; i < n ; i++)
    {
        cin >> a;
        gain.push_back(a);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    vector<int> answer(n+1, 0);
    answer[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        answer[i] = answer[i-1] + gain[i-1];
    }
    cout << *max_element(answer.begin(), answer.end()) << endl;
    return 0;
}