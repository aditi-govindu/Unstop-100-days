#include <bits/stdc++.h>
using namespace std;

/*
Description: Marco likes matrix a lot. His friend given him a m x n matrix mat and an integer k, and asked him to return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
Help Marco to solve this problem.
*/

void matrixBlockSum(vector<vector<long long>>& mat, long long k) 
{
    long long n=mat.size();
    long long m=mat[0].size();
    vector<vector<long long>>dp(n,vector<long long>(m,0));
    for(long long i=0;i<n;i++) 
    {
        for(long long j=0;j<m;j++) 
        {
            dp[i][j]=mat[i][j];

            if(i>0)
                dp[i][j]+=dp[i-1][j];	
            
            // prefix sum for every rectangle possible in the matrix
            if(j>0)dp[i][j]+=dp[i][j-1];
            if(i>0&&j>0)dp[i][j]-=dp[i-1][j-1];
        }
    }
    
    for(long long i=0;i<n;i++) 
    {
        for(long long j=0;j<m;j++) 
        {	
            // finding the rectangle edge points
            long long lfx=max(0*1ll,j-k);
            long long rtx=min(m-1,j+k);
            long long lfy=max(0*1ll,i-k);
            long long rty=min(n-1,i+k);

            mat[i][j]=dp[rty][rtx];

            if(lfy>0)mat[i][j]-=dp[lfy-1][rtx];
            if(lfx>0)mat[i][j]-=dp[rty][lfx-1];
            if(lfy>0&&lfx>0)mat[i][j]+=dp[lfy-1][lfx-1];	// storing the sum according to edge points
            
        }
    }
    
    for(long long i=0;i<n;i++) 
    {
    	for(long long j=0;j<m;j++) 
    		cout << mat[i][j] << " ";
    	cout << "\n";
    }
}

int main() 
{	
	long long n, m, k;
	// take inputs
	cin >> m >> n >> k;
	vector <vector<long long> > matrix;
	
	for(long long i=0;i<m;i++) 
    {
		vector<long long> temp;
		for(long long j=0;j<n;j++) 
        {
			long long x;
			cin>> x;
			temp.push_back(x);
		}
		matrix.push_back(temp);
	}
	
	matrixBlockSum(matrix, k);
	
	return 0;
}