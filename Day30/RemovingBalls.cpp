#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*
Description: Aryan and Ankit play a game with n boxes . There are an even number of boxes arranged in a row, and each box has a positive integer number of stones balls, denoted by balls(i).

The objective of the game is to end with the most balls. The total number of balls across all the boxes is odd, so there are no ties.

Aryan and Ankit take turns, with Aryan starting first. Each turn, a player takes the entire balls from the box either from the beginning or from the end of the row. This continues until there are no more boxes left.

At the end, the person with the most balls wins.

Assume Aryan and Ankit play optimally.

Print Aryan if Aryan wins and print Ankit if Ankit wins.
*/

using namespace __gnu_pbds;
using 	namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


template<class T> using omset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// ub --> lb, lb-->ub
//  os.order_of_key(x) --> no. of elements strictly less than x, returns an integer
// os.find_by_order(x-1) --> returns an iterator to xth element, 1-based indexing.

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


bool Game(vector<int>&a) 
{
    int n = a.size();
    int dp[n][n];
    
    for(int i=0;i<n;i++)
        dp[i][i]=a[i];
    
    for(int i=0;i<n-1;i++)
        dp[i][i+1]= max(a[i],a[i+1]);
    
    for(int len=3;len<=n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int j= len + i -1;
            
            if(i>=j || j>=n || i>=n) 
                continue;
            
            int op1= a[i] + min({ dp[i+1][j-1], dp[i+2][j]});
            
            int op2= a[j] + min({dp[i+1][j-1], dp[i][j-2]});
            
            dp[i][j]= max(op1,op2);
            
        }
    }
    
    int sum=0;
    for(int i=0;i<n;i++) 
        sum+=a[i];
    
    int aryan_score= dp[0][n-1];
    int ankit_score= sum- aryan_score;

    return aryan_score>=ankit_score;
}


int32_t main()
{
	fio;

	int n; cin>>n;

	vector<int>a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	if(Game(a))
		cout<<"Aryan"<<endl;
	else
		cout<<"Ankit"<<endl;
}