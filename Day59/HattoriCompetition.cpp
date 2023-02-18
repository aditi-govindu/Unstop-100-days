#include <bits/stdc++.h>
using namespace std;

/* Description: Recently there's been a competition in ninja land where every ninja wants to win the prize, but our favourite ninja Hattori wants to win the prize so he does some precomputation before the competition starts. The competition is such that there are n points from  and every point a ninja is given a power in which he can jump  steps. Find the minimum number of moves in which Hattori can make to the endpoint.
*/

int main() 
{
    int n;
    cin >> n;

    vector<int>nums(n);
    vector<int> dp(n, 10001);

    // Set last index to no jumps needed
    dp[n - 1] = 0; 

    for(int i = 0; i<n; i++)
        cin>>nums[i];
    
    for(int i = n - 2; i >= 0; i--) 
    {
        // Store current jump as minimum of previous, (current index + jump)
        for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
            dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);
    }
    cout << dp[0] << endl;
    
    return 0;
}