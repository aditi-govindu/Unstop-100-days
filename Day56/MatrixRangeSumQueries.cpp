#include <bits/stdc++.h>
using namespace std;

/*
Description: You are given a matrix of integers and there will be Q queries. 
You have to write a class NumMatrix and the function sumRegion.
An object of the class NumMatrix will be created and some queries will be made.
sumRegion finds the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*/

class NumMatrix 
{
    public:
        vector<vector<int>> a;
        NumMatrix(vector<vector<int>>& m) 
        {
            int n = m.size();
            int x = m[0].size();
            for(int i=0;i<n;i++)
            {
                for(int j=1;j<x;j++)
                    m[i][j] += m[i][j-1];   
            }
            a = m;
        }
    
        int sumRegion(int row1, int col1, int row2, int col2) 
        {
            int sum = 0;
            int  j = col2;
            for(int i = row1;i<=row2;i++)
            {
                int k = (col1 - 1 >= 0 ? col1 - 1 : -1);
                if(k != -1)
                    sum += (a[i][j] - a[i][k]);
                else
                    sum += a[i][j];
            }
            return sum;
        }
    
};

int main ()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>matrix[i][j];
        }
    }

    NumMatrix* obj = new NumMatrix(matrix);
    
    int q;
    cin>>q;
    for (int i = 0; i < q; ++i)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<obj->sumRegion(r1,c1,r2,c2)<<endl;
    }
    return 0;
}