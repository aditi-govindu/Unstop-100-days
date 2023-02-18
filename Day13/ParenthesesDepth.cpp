#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

/*
Description: Dhruv is given a string, If a string matches one of the following criteria, it is a valid parentheses string (abbreviated VPS).

It can be represented as AB (A concatenated with B), if A and B are VPSs, or as (A), where A is a VPS.
We may define the nesting depth depth(S) of any VPS S in the same way:

depth("") = 0
depth(C) = 0, where C is a string containing a single character that is not "(" or ")".
depth(A + B) = max(depth(A), depth(B)), where A and B are virtual private servers.
depth("(" + A + ")") = 1 + depth(A), where A is a virtual private server.
"", "()()", and "()(()())" are VPSs (with nesting depths 0, 1, and 2), whereas "(" and "(()" are not.

Help Dhruv calculate the nesting depth of a VPS expressed as a string s.
*/

using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    string str;
    int longest = 0;
    int curr = 0 ;

    cin >> n;
    cin >> str;

    for(auto &letter: str)
    {
        // Increment for every ( and decrement for every )
        if(letter == '(')
            curr++;
        else if(letter == ')')
            curr--;
        longest = max(longest, curr);
    }
    cout << longest << endl;
    return 0;
}