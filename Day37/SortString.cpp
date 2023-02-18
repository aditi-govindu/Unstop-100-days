/*
Description: You are given a string s. You have to sort the string in a way that the character with the greatest number of repetitions comes first. If there are multiple characters with same number of repetitions sort them in lexicographically.
*/

#include<bits/stdc++.h>
using namespace std;

string solve(string s) 
{
    //storing frequency in a vector
    int cnt[128] = {};
    for (char c : s) cnt[c] += 1;
    //custom sort function that would compare the freq
    //and will return character with higher frequency
    sort(s.begin(), s.end(), [&](char a, char b) 
    {
        return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
    });
    //return answer
    return s;
}

int main()
{
    //input
    string s;
    cin>>s;
    //printing answer
    cout<<solve(s);
    return 0;
}