#include <bits/stdc++.h>
using namespace std;
/*
Description: You are a shopkeeper and bought n pairs of socks of several colours in bulk. The colour of each pair of socks is represented as a non-negative integer. The socks are sold as sets of 3 pairs each. A set of socks consists of 3 pairs of the same colour.

You want to find the number of different sets that can be made from the n pairs of socks you bought today. Note: order of indices of sock pairs in the set does not matter.
*/

int nC3(int n)
{
    if(n < 3)
        return 0;
    
    return (n*(n-1)*(n-2))/6;
}

int main()
{
    // read inputs
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i:a)
        cin >> i;

    // map to store frequencies
    map<int, int> freq;
    for(int i: a)
        freq[i]++;
    
    // initialize answer as 0
    int ans = 0;

    // for all elements in the map, add
    // nC3 to the answer
    map<int, int>::iterator it;
    for(it = freq.begin(); it != freq.end(); it++){
        ans += nC3(it->second);
    }

    // print the answer
    cout << ans << endl;

    return 0;
}