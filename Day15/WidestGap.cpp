#include<bits/stdc++.h>

using namespace std;
/*
Description: Ram gave Shyam n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
Note that points on the edge of a vertical area are not considered included in the area.
*/
int maxWidthOfVerticalArea(vector<vector<int>>& points) 
{

        vector<int> x;
        for (int i=0;i<points.size();i++)
        {
            x.push_back(points[i][0]);
        }

        sort(x.begin(),x.end());
        int ans=0;
        int last=INT_MAX;
        for(int i=0;i<x.size()-1;i++)
        {
            ans=max(ans,x[i+1]-x[i]);
        }

        return ans;
    }

void solve()
{

  int n; 
  cin>>n;

  std::vector<std::vector<int>> v(n,std::vector<int>(2,0));

  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    v[i][0]=a;
    v[i][1]=b;
  }

  cout<<maxWidthOfVerticalArea(v);

}

signed main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;

}