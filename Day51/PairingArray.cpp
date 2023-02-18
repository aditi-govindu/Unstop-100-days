#include<bits/stdc++.h>
using namespace std;
#define ll long long 

/*
Description: Ram was playing with an array when he got to know the existence of different patterns found in arrays. He wrote code for different kinds of patterns and enjoyed it a lot, one day he got stuck in a pattern and asked for your help.

He gave you an array let’s call it arr and asked you to find the number of pairs of (i,j) such that given a number k :

0<=i<j<=arr.length - 1
arr[i] * arr[j] is divisible by k.
Given an array and a number k, find the number of pairs of elements in the array such that their product is divisible by k.
*/

int main()
{
    ll k;
    cin>>k;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    ll ans = 0;
    map<ll, ll> mp;
    for(auto it : arr)
    {
        // Find GCD of number and k
        int gc = __gcd(k, it); 
        for(auto it1 : mp)
        {
            // If GCD of both numbers is 0, increment count
            if((it1.first*gc)%k == 0)
                ans += it1.second;
        }
        // Storing the gcd with k in the map
        mp[gc]++; 
    }
    cout<<ans<<endl;
    return 0;
}