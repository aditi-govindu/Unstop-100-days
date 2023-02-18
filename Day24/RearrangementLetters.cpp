#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Description: You are given two strings, p and q, return true if q is an anagram of p and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. For example, the word anagram itself can be rearranged into nag a ram, the word binary into brainy and the word adobe into the abode.
*/

bool checkAnagram(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    // String lengths unequal, not anagrams
    if(n1 != n2)
        return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i = 0; i < n1; i++)
    {
        // If any letter is not at the same position, anagram is not found
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string p;
    string q;

    cin >> p;
    cin >> q;

    if(checkAnagram(p, q))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}