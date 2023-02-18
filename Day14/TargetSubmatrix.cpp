#include<bits/stdc++.h>
using namespace std;

/*
Description: Ram gave Shyaam a matrix and a target, he challenged Shyaam to find how many submatrices are there such that the sum of all their elements is equal to target. The submatrices should be non empty.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
*/

int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];

        unordered_map<int, int> counter;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }

void solve()
{
  int n,m; cin>>n>>m;
  std::vector<std::vector<int>> v(n,std::vector<int>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int a;
        cin>>a;
        v[i][j]=a;
    }
  }
  int target;
  cin>>target;
  cout<<numSubmatrixSumTarget(v,target);
}

signed main()
{ 
	ios_base::sync_with_stdio(false); 
    solve();
    
    return 0;
}