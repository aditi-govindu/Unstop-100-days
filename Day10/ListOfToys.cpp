#include <bits/stdc++.h>
using namespace std;

/*
Description: A toy manufacturing factory produced n toys on a day. The manager has a list of product IDs and another list containing the sizes of the corresponding toys of length n each. In other words, the ith integer in the product sizes list represents the size of the ith toy in the product ID list. He accidentally added the second list in front of the first one and now has a list of 2*n elements.

You are an employee, and the manager wants you to recover the data and present it to him as another list of 2*n elements such that the product ID of each toy is followed by its size.
*/

int main()
{
    // read inputs
    int n;
    cin >> n;
    int a[2*n];
    for(int i = 0; i < 2*n; i++)
        cin >> a[i];

    vector<int> res;
    // For the first n elements, find the
    // size of the ith element and push them
    // at the end of result
    for(int i = 0; i < n; i++){
        res.push_back(a[i]);
        res.push_back(a[i+n]);
    }

    // print the result
    for(int i: res)
        cout << i << ' ';

    return 0;
}