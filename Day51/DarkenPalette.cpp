#include <bits/stdc++.h>
using namespace std;

/*
Description: You are an artist, and your palette is in the shape of an n x n grid. The groove in the ith row and jth column has a shade of a colour with darkness represented by a non-negative integer ai, j.

You want to make this palette as dark as possible but not make any colour darker than the darkest colour already present in its corresponding row and column. In one step, you can increase the darkness of any one colour by 1. Find the number of steps it will take to make all colours in the palette as dark as possible.

Note: the changes are performed independently; none of them changes the palette for the next step.
*/

int main()
{
    // read inputs
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    // let the answer be 0 initially
    int ans = 0;

    vector<int> row_max(n, 0), col_max(n, 0);

    // compute the row_max array
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            row_max[i] = max(row_max[i], a[i][j]);

    // compute the col_max array
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n; i++)
            col_max[j] = max(col_max[j], a[i][j]);
    
    // compute the answer
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // Color the palette with color smaller than max of row/column - current value
            int new_val = min(row_max[i], col_max[j]);
            ans += new_val - a[i][j];
        }
    }
    // print the answer
    cout << ans << endl;

    return 0;
}