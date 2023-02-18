/*
Description: A binary tree could be stored as an array, where the child of node at  i th index is stored in  (2*i-1) th index and (2*i)th index, assuming 0 based indexing.

A binary tree is called a single valued tree if the values of all the nodes are the same.

If the given binary tree is single valued print true else print false.
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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



int32_t main()
{
	fio;

	set<int>se;

	vector<int>a;
	int x;

	while(cin>>x){
		a.push_back(x);
	}
	bool flag=0;
	
	for(int i=1; i<a.size(); i++)
    {
		if(a[i]==-1) continue;
		if(a[i]==a[0]) continue;
		flag=1;
	}

	if(flag){
		cout<<"False"<<endl;
	}
	else{
		cout<<"True"<<endl;
	}
}