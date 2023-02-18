#include <bits/stdc++.h>
using namespace std;

/*
Description: On a far-off planet, a baby alien has n blocks to play with. Each block has a lowercase English alphabet written on it. He arranged the blocks in a line and created a string s. The baby’s name is another string p of length m.

The baby can pick m consecutive blocks from his string of blocks and rearrange them to form his name. Now, he wants to find out all such groups of m consecutive boxes that can be rearranged to form his name.
*/

int main()
{
    // read inputs
    string s, p;
    cin >> s >> p;

    // lengths of strings
    int n = s.length(), m = p.length();

    // maps to store frequencies of all characters
    map<char, int> p_freq, s_freq;
    // vector to store results
    vector<int> res;

    // build the map for string p
    for(char c: p)
        p_freq[c]++;
    
    // build the map for first m
    // characters of s
    for(int i = 0; i < m; i++)
        s_freq[s[i]]++;

    // check if the frequencies in both maps
    // are the same
    bool ok = true;
    for(char c = 'a'; c <= 'z'; c++)
        if(s_freq[c] != p_freq[c])
            ok = false;
    
    // if yes, add the starting index to 
    // the result
    if(ok)
        res.push_back(1);

    // for each index after m, slide the window
    // and compare frequencies of characters
    for(int i = m; i < n; i++){
        // remove the leftmost character
        s_freq[s[i - m]]--;
        // add the next character
        s_freq[s[i]]++;
        ok = true;
        // compare the frequencies
        for(char c = 'a'; c <= 'z'; c++){
        if(s_freq[c] != p_freq[c])
            ok = false;
        }
        // if the frequencies are the same, 
        // add the starting index to the 
        // result
        if(ok)
            res.push_back(i - m + 2);
    }

    // print the results
    cout << (int) res.size() << endl;
    for(int i: res)
        cout << i << ' ';
    return 0;
}