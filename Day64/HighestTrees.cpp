/*
Description: From your balcony, you can see n trees standing in a line numbered from 1 to n. The ith tree has height hi. Using your binoculars, you can only look at k trees at once in a single frame. A frame is defined by the index of the leftmost tree in it and contains exactly k trees. Starting from frame 1 (the leftmost frame), you move your binoculars towards the right until you reach frame n-k+1 (the rightmost possible frame). You want to find the height of the highest tree in each frame that is captured by your binoculars
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // read inputs
    int n, k;
    cin >> n >> k;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    // initialize intermediate and result arrays
    int left[n], right[n], res[n-k+1];

    // compute left array
    for(int i = 0; i < n; i++)
    {
        // beginning of a new block
        if(i % k == 0)
            left[i] = a[i];
        else
        {
            // using concepts of dynamic programming
            // compute left[i] using left[i-1]
            left[i] = max(left[i-1], a[i]);
        }
    }

    // compute right array
    // initialize first element in case n%k != 0
    right[n-1] = a[n-1];
    for(int i = n - 2; i >= 0; i--){
        if(i % k == 0)
            right[i] = a[i];
        else
        {
            // using dynamic programming
            // compute right[i] using right[i+1]
            right[i] = max(right[i+1], a[i]);
        }
    }

    // computing result array
    for(int i = 0; i < n - k + 1; i++)
        res[i] = max(left[i + k - 1], right[i]);

    // printing the result array
    for(int i: res)
        cout << i << ' ';

    return 0;
}