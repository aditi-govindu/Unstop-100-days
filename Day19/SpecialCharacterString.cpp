#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Ram was learning about strings, he read from the internet and got to know that the string is a series of characters. He was solving a problem and he got stuck and asked you for his help.

The problem defined a special character of the string as the first nonrepeating character in the string.

Given a string find the special character in it.
*/

void firstNonRepeat(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if (s.find(s[i], s.find(s[i]) + 1) == string::npos)
        {
            cout << s[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    string s;

    cin >> n;
    cin >> s;
    firstNonRepeat(s);

    return 0;
}