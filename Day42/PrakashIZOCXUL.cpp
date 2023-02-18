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

/*
Description: Prakash was seeing a dream, where he used to live on a planet named IZOCXUL. The letters used in that planet were similar to those used in the English language, but the order was reversed, i.e the first character is z, second character is y, and so on with last character being a. The planet uses only lower case letters.

Given a sequence of letters[String], find the count of the substrings of size 2 to K, where each substring has unique characters.
*/

int32_t main()
{
	fio;

	string s; cin>>s;
	int k; cin>>k;

	map<int,int>mp;
	set<char>se;
   
	for(int i=0; i<s.size(); i++){
		se.clear();
		se.insert(s[i]);
		for(int j=2; j<=k; j++){
            
            if(i+j-1>=s.size()) break;
            
			se.insert(s[i+j-1]);
			if(se.size()==j){
				mp[j]++;
			}
            
		}
	}

	for(int i=2; i<=k; i++){
		cout<<mp[i]<<endl;
	}


	
}