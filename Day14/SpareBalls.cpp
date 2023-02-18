/*
Description: You have n boxes numbered from 1 to n. Each box has a number of balls inside it. You have m spare balls, and you can choose to put them all into any box of your choice.

For each box, you want to know that if you put the balls in it, will it become the box with the highest number of balls or not. Note that multiple boxes can have the maximum number of balls.

Brute Force Method:

After adding the spare balls in each box, we can compare it with the entire array to check if there exists any box with a greater number of balls.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // read inputs
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    // vector to store results
    vector<int> res;

    // maximum element in the given array
    int mx = *max_element(a.begin(), a.end());

    // find the answer for each element
    for(int i = 0; i < n; i++){
        bool ok = true;

        // if the maximum element in the array
        // is more than the sum of current element
        // and spare balls, answer will be false
        if(a[i] + m < mx)
            ok = false;

        // based on the result, push 1 or 0 in
        // the resultant vector
        if(ok)
            res.push_back(1);
        else
            res.push_back(0);
    }

    // print the result
    for(int i: res)
        cout << i << ' ';
    return 0;
}