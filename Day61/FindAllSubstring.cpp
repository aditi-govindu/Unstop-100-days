#include <bits/stdc++.h>
using namespace std;
/*
Description: You are given a string str. Your task is to find all the unique substring of size 10 which occurred more than once in str. You have to return the strings in the same order in which they have occurred in str.

Note -  String str contains only 3 characters i.e ‘A’, ‘B’ and ‘C’.
*/

vector<string>solve(string s)
{
    vector<string> ans;
    unordered_map<string, int> mp,mp1;
    
    if(s.size()<10) return ans;
    
    for(int i=0;i <= s.size()-10;i++) 
    mp[s.substr(i,10)]++;
    
    for(int i=0;i <= s.size()-10;i++)
    {
        string a = s.substr(i,10);
        if(mp[a]>1 and mp1[a]==0)
        {
            ans.push_back(a);
            mp1[a]=1;
        }
    }
    return ans;
}

int main() 
{
    string str;
    cin>>str;
    
    for(auto i : solve(str))
    {
        cout<<i<<" ";
    }
    return 0;
}