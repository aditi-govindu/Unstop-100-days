/*
Description: Challenge, really!!!!! That's what two friends where discussing standing on bus stand waiting for a bus to come,instead of wasting time so they challenge to solve one problem.Among two friends one friend agrees to solve this problem.

This is the  Upper and Lower Challenge :

Given a string s, you can convert each letter to lowercase or uppercase to construct another string.

Return a list of all the strings that could be created. Return the output in any format.

*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void dfs(string s, int idx, int n, string str, vector<string> &vt)
{

  if(idx == n)
  {
    vt.push_back(str);
    return;
  }

  if(s[idx] >= 'a' && s[idx] <= 'z')   
    dfs(s, idx+1, n, str+char(s[idx]-'a'+'A'), vt);

  else if(s[idx] >= 'A' && s[idx] <= 'Z')   
    dfs(s, idx+1, n, str+char(s[idx]-'A'+'a'), vt);

  dfs(s, idx+1, n, str+s[idx], vt);

  return;       
}


int main() 
{

    int n; cin >> n;
    string s; cin >> s;
    vector<string> vt;
    dfs(s, 0, n, "", vt);

  for(auto x : vt)
    cout << x << " ";
  return 0;
}