#include <bits/stdc++.h>
using namespace std;

/*
Description: During the class on data structure and algorithm, Professor gave students a string-based problem to solve and bet if anyone solve the problem will get full marks for endsem. Problem states that we are given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character with a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

We have to print the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.
*/

int countSubstrings(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<int>> dp1(n+1,vector<int>(m+1));
    int ans = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                dp1[i][j] = dp1[i-1][j-1];
            }
            else
                dp1[i][j] = 1+dp[i-1][j-1];
            ans += dp1[i][j];
        }
    }
    return ans;
}

signed main() {
    string s,t;
    cin>>s>>t;
    cout<<countSubstrings(s,t);
}