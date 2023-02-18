#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*
Description: Akarsh gives Aryan n 2D points. Aryan plots the points on the Cartesian plane and he wants to observe how many maximum points lie on a line.

Write an algorithm to help Aryan.

Assumptions → No two points in the input are the same.
*/

using namespace __gnu_pbds;
using 	namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


template<class T> using omset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;

using 	ll=long long;
using 	ld=long double;
#define gcd __gcd
#define double long double
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)     	__builtin_ctzll(x)
#define fio 			ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ff 				first
#define ss 				second
#define pb 				push_back 
#define eb 				emplace_back
#define deci(x,y) 		fixed<<setprecision(y)<<x
#define all(x)     		x.begin(),x.end()
#define maxe 			*max_element
#define mine 			*min_element
#define lb 				lower_bound
#define ub 				upper_bound
#define endl 			'\n'
#define infl 			1e18
#define inf 			2e8
#define MAX 			100005
#define int 			long long
#define w(x)    		ll x; cin>>x; while(x--)
const int mod= 1e9+7;


// Store slopes of lines in a hashmap
 pair<int,int>slope(int i, int j, vector<vector<int>>&points)
 {       
        if(points[i][1] == points[j][1])
            return {inf,inf};

        int m1 = points[i][0]-points[j][0];
        int m2=points[i][1]-points[j][1];
        
        int m_gcd = __gcd(m1,m2);
        m1/=m_gcd;
        m2/=m_gcd;
        
        return {m1,m2};
    }


      int solve(vector<vector<int>>& points) 
      {
        if(points.size()==1) return 1;
        int cur_ans=0;
        int n=points.size();
        
     
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            
            map<pair<int,int>,int>mp;
            
            for(int j=0; j<n; j++)
            {
                if(i==j) 
                    continue;

                // If slopes are identical, increment count
                int m1= slope(i,j,points).first;
                int m2= slope(i,j,points).second;
                mp[{m1,m2}]++;
              
            }
            
            for(auto it:mp)
                cur_ans = max(cur_ans, it.second);
            
            ans = max(ans, cur_ans+1);
            
        }
        
        return ans;
    }


int32_t main()
{
	fio;

	int n; cin>>n;
	vector<vector<int>>points;
	for(int i=0; i<n; i++)
    {
		int x,y; 
        cin >> x >> y;
		points.push_back({x,y});
	}

	cout<<solve(points);
}