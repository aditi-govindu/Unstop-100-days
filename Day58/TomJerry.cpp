#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Tom and Jerry are very naughty they always fight each other even for little things. This time they started fighting over a small cookie. The situation is such that there is a stream of numbers on a number line where there is a cookie present at the kth largest element in the array. Since Tom always gets the cookie from the master. Can you help jerry in getting the cookie as fast as possible?
*/

int main() 
{
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    
    // Display kth largest element in array
    sort(numbers.begin(), numbers.end());
    cout << numbers[n - k] << endl;

    return 0;
}