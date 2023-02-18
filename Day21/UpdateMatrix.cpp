#include<bits/stdc++.h>
using namespace std;

/*
Description: There is an m x n matrix that is initialized to all 0's. 
There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed 
location to perform some increment operations on the matrix.

For each location indices[i], do both of the following:

Increment all the cells on row ri.

Increment all the cells on column ci.

Given m, n, and indices, return the number of odd-valued cells in 
the matrix after applying the increment to all locations in indices.
*/

int oddCells(int n, int m, vector<vector<int>>& indices) 
{
    vector<bool> N(n, false);
    vector<bool> M(m, false);

    for(int i=0; i<indices.size(); i++) 
    {
        N[indices[i][0]] = N[indices[i][0]]^true;
        M[indices[i][1]] = M[indices[i][1]]^true;
    }

    int r = 0;
    int c = 0;

    for(int i=0; i<n; i++) 
    {
        if(N[i])
            r++;
    }

    for(int j=0; j<m; j++) 
    {
        if(M[j])
            c++;
    }

    return  r*m + c*n - 2*r*c;
}

void solve()
{
  int n,m; 
  cin>>n>>m;

  int q; 
  cin>>q;
  vector<vector<int>> indices;

  for(int i=0;i<q;i++)
  {
    int a,b;
    cin>>a>>b;
    indices.push_back({a,b});
  }
  cout<<oddCells(n,m,indices);
}

signed main()
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
    
    return 0;
}