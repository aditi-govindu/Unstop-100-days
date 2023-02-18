/*
Description: You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == color.
ruleKey == "name" and ruleValue == namei.
Print the number of items that match the given rule.
*/

#include <bits/stdc++.h>
using namespace std;

int MatchingCount(vector<vector<string>>& items, string ruleKey, string ruleValue) 
{
    int res = 0, key = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    for (auto item : items)
    {
         if (item[key] == ruleValue)
              res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> items(n,vector<string>(3));

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<3;j++)
      cin>>items[i][j];
    }

    string ruleKey,ruleValue;
    cin>>ruleKey>>ruleValue;
    cout<<MatchingCount(items,ruleKey,ruleValue);
    return 0;
}