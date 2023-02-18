#include <bits/stdc++.h>
using namespace std;

/*
Description: Alex and Bob got one problem from their friend But after hours of Trying, 
they got frustrated. Now they hire you as a freelancer to solve this problem. 
The problem states that you are given a string s of even length consisting of digits 
from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. 
For example, if s = "3456" and a = 5, s becomes "3951".
Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
Print the lexicographically smallest string you can obtain by applying the above operations 
any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) 
if in the first position where a and b differ, string a has a letter that appears 
earlier in the alphabet than the corresponding letter in b. For example, "0158" 
is lexicographically smaller than "0190" because the first position they 
differ is at the third letter, and '5' comes before '9'.
*/

set<string> v;
string add(string s,int a){
    string x;
    for(int i=0;i<s.size();i++){
        if(i%2 != 0){
            x += (((s[i] - '0') + a)%10 + '0');
        }else{
            x += s[i];
        }
    }
    return x;
}

string rotate(string s,int b){
    string x;
    int n = s.size();
    x += s.substr(n-b);
    x += s.substr(0,n-b);
    return x;
}

void solve(string s, int a, int b,string &ans){
    if(v.find(s) != v.end()) return;
    v.insert(s);
    ans = min(s,ans);
    solve(add(s,a),a,b,ans);
    solve(rotate(s,b),a,b,ans);
}

string findLexSmallestString(string s, int a, int b) {
    string ans = s;
    solve(s,a,b,ans);
    return ans;
}

signed main() {
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    cout<<findLexSmallestString(s,a,b);
}