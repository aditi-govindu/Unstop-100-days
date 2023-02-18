#include <bits/stdc++.h>
using namespace std;

/*
Description: Ohh!!!! what a problem your teacher gave to you as a challenge.
That was like a string is a valid parentheses string (abbreviated VPS) if and only if it 
contains only "(" and ")" characters, and it meets the following criteria:

It can be represented as AB (A concatenated with B), where A and B are virtual 
private servers, or as (A), where A is a virtual private server.
The nesting depth depth(S) of any VPS S can be defined similarly:

depth("") = 0 depth(A + B) = max(depth(A), depth(B)), where A and B are VPSs 
depth("(" + A + ")") = 1 + depth(A), where A is a VPS depth("(" + A + ")") = 1 + depth(A), 
where A is a VPS
"", "()()", and "()(()())" are VPSs (with nesting depths 0, 1, and 2), whereas "", "()()", 
and "()(()())" are not.

Split a VPS seq into two distinct subsequences A and B, each of which is a VPS 
(and A.length + B.length = seq.length).

Select any A and B such that max(depth(A), depth(B)) is the smallest value feasible.

You need to return a response array (of length seq.length) 
encoding such an A/B choice: answer[i] = 0 if seq[i] is part of A, otherwise answer[i] = 1. 
Even if there are numerous answers, you may choose any of them to return.
*/

int main() 
{
  int n; cin >> n;
  string seq; cin >> seq;
  
  int idx = 0, maxdepth = 0, d = 0;
  vector<int> arr(n);

  for(int i = 0; i < n; i++)
  {
    // Increment count for (
    if(seq[i] == '(')
    {
        d++;          
        arr[i] = d;
    }
    else
    {
        // Decrement count for ) bracket
        arr[i] = d;
        d--;
    }
    
    if(maxdepth < d)
        maxdepth = d;                
  }
  
  for(int i = 0; i < n; i++)
  {
      // If maximum depth of parenthesis not reached, print 0
    if(2*arr[i] <= maxdepth)
        arr[i] = 0;
    else
        arr[i] = 1;
  }  
  
  for(int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << '\n';
  
  return 0;
}