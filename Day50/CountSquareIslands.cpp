#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* Description: Given a n * m matrix of ones and zeros, where 0 denotes water 
and 1 denotes island now you have to count the number of square sub-island. 
*/

int maximalSquare(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int> (n,0));
    int sum = 0;
    
    for(int i=0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // If square is 0, set to matrix value
            if(i == 0 || j == 0)
                dp[i][j] = matrix[i][j];
            else
            {
                // Find square submatrices
                dp[i][j] = (matrix[i][j] == 1) ? 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) : 0;
            }
        }
    }

    // Count subsquares seen
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            sum += dp[i][j];
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m, n;

    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    cout << maximalSquare(matrix);    

    return 0;
}