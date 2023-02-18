#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/*
Description: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

stack<char> st;

bool isValid(string s) 
{
    for(int i = 0; i < s.length(); i++)
    {
        // Check mathcing brackets
        if(st.empty())
            st.push(s[i]);
        else if(s[i] == ')' && st.top() == '(')
            st.pop();
        else if(s[i] == '}' && st.top() == '{')
            st.pop();
        else if(s[i] == ']' && st.top() == '[')
            st.pop();
        else
            st.push(s[i]);
    }
    if(st.empty())
        return true;
    return false;
}

int main()
{
    string s;
    cin >> s;

    bool ans = isValid(s);
    if(ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}