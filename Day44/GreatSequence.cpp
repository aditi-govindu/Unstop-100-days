/*
Description: A sequence of positive integers is called great for a positive integer x, 
if we can split it into pairs in such a way that in each pair the first number multiplied by 
x is equal to the 
second number. More formally, a sequence a of size n is great for a positive integer x, 
if n is even and there exists a permutation p of size n, such that for each i (1 ≤ i ≤ n/2)

Sam has a sequence a and a positive integer x. Help him to make the sequence great: find the minimum possible number of positive integers that should be added to the sequence a to 
make it great for the number x.
*/

#include <bits/stdc++.h>
using namespace std;
 
signed main() 
{
    ios_base::sync_with_stdio(false); 
    int n;
    int64_t x;
    cin >> n >> x;
    vector<int64_t> ar(n);

    for (auto& it : ar)
        cin >> it;
    sort(ar.begin(), ar.end());
    vector<bool> vis(n);

    int j = 0, q = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) 
    {
        if (vis[i])
            continue;
        
        if (ar[i] * x > ar[j]) 
        {
            // Keep track of letter appearance
            while (ar[i] * x >= ar[j] && j < n)
                q = ++j;
            // Subtract minimum no. of occurences of the letter
            q = --j;
        }
        // If letter already considered, remove it
        if (i < q && ar[i] * x == ar[q])
            vis[q--] = 1;

        // Display final answer
        else
            ans++;
    }
    cout << ans << "\n";

    return 0;
}