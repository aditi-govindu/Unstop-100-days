/*
Description: A player is initially on position 1. He can jump x steps forward, or come x steps backwards. He must memorise all his positions he has been to in previous moves.

There are two types of queries : each query is of the type (a b)

Type 1→ will be of the form 1 b

          We have to go to the position b from our current position.

Type 2→ Will be of the form 2 b

          Print the position we were at b moves prior, 1 move later is the position from where we reached our current position and likewise also change the current position to this new position.

          If going b moves is not possible then print -1.
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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



int32_t main()
{
	fio;

	int q; 
    cin>>q;

	vector<int>v;
	v.push_back(1);
	int cur_idx=0;

	while(q--)
    {
		int a,b; 
        cin>>a>>b;
		if(a==1)
        {
			if(v.size() == cur_idx+1)
			{
			    v.pb(b);
			    cur_idx++;
			}
			else
            {
				v[cur_idx+1] = b;
				cur_idx++;
			}
		}
		else
        {
			if(cur_idx>=b)
            {
				cur_idx-=b;
				cout<<v[cur_idx]<<endl;
			}
			else
            {
				cout<<-1<<endl;
			}
		}
	}

	
}