#include <bits/stdc++.h>
using namespace std;
/*
Description: Vikas is trying to find words that can be formed out of given characters, help him solve the below given puzzle.

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.
*/

int countCharacters(vector<string>& words, string chars) 
{
    vector<int> chFreq(26, 0);
    for(auto ch : chars) chFreq[ch - 'a']++;
    int count = 0;
    for(auto str : words)
    {
        bool flag = true;
        vector<int> copyFreq(26, 0);
        for(auto ch : str) 
        {
            if(++copyFreq[ch - 'a'] > chFreq[ch - 'a'])
            {
                flag = false;
                break;
            }
        }
        if(flag) count += str.size();
    }
    return count;
}

int main() 
{ 
    string chars;
    int n, result;
    cin>>n;
    vector<string> words(n);
    for(int i=0; i<n; i++)
    {
        cin>>words[i];
    }
    cin>>chars;
    result = countCharacters(words, chars);
    cout<<result;
    return 0; 
}