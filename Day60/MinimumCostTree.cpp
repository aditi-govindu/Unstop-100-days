#include <bits/stdc++.h>
using namespace std;

/*
Description: Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;

The values of arr correspond to the values of each leaf in an in-order traversal of the tree.

The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.
*/

int mono_stack(vector<int>& v) 
{
    int c = 0;
    stack<int> st;
    for(int i:v) 
    {
        while(!st.empty() && st.top() <= i) 
        {
            int x = st.top();
            st.pop();
            c += x * min(st.empty() ? INT_MAX : st.top(),i);
        }
        st.push(i);
    }

    int a = st.top();
    st.pop();

    while(!st.empty()) 
    {
        int x = st.top();
        st.pop();
        c += x * min(st.empty() ? INT_MAX : st.top(), a);
        a = x;
    }
    return c;
}

void solve () 
{
    int n;
    cin>>n;
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << mono_stack(v);
}


int32_t main() 
{
    ios_base::sync_with_stdio(false); 
    solve();
    
    return 0;
}