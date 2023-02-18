#include <bits/stdc++.h>
using namespace std;

/*
Description: Bolt is the best coder in his school. One day competition held at their college in which you have to solve only one question and also can take help from anyone. During the competition bolt unable to solve the problem so he tried to take help from you. Now you have to solve the following problem to help bolt win the competition.

You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Print a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.
*/

vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) 
{
        int n = r.size();
        int m = c.size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If column greater than row, reset value
                if(c[j] >= r[i])
                {
                    ans[i][j] = r[i];
                    c[j] -= r[i];
                    r[i] = 0;
                }
                else
                {
                    ans[i][j] = c[j];
                    r[i] -= c[j];
                    c[j] = 0;
                }
            }
        }
        return ans;
    }

signed main() 
{
    int n,m;
    cin>>n>>m;
    vector<int> row(n), col(m);

    for(int i=0;i<n;i++)
        cin>>row[i];

    for(int i=0;i<m;i++)
        cin>>col[i];

    vector<vector<int>> ans = restoreMatrix(row,col);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}