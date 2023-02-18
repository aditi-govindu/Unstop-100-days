/*
Description: Alex and bob want to find out the common characters in between N numbers of strings of names. Help Alex and bob find it.
Print the output in lexicographically order.
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> check_name(vector<string>& words) 
    {
        // Keep track of frequency
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (auto s : words)
        {
            vector<int> cnt1(26, 0);
            //This would store frequency between 2 strings at a time 
            
            for (auto c : s) 
                ++cnt1[c - 'a'];
            // Store the minimum number of counts of the elements
            for (auto i = 0; i < 26; ++i) 
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        for (auto i = 0; i < 26; ++i)
            for (auto j = 0; j < cnt[i]; ++j) 
                res.push_back(string(1, i + 'a'));
                //appending answer vector
        return res;

    }
int main()
{
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
        //taking input
        string str;
        cin>>str;
        s[i]=str;
    }
    auto x=check_name(s);
    for(auto y:x)
    cout<<"["<<y<<"]";//printing results
    return 0;
}