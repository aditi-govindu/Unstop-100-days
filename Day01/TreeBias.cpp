/*
Description: Ram was learning the tree data structure when John saw him. Seeing Ram John challenged him to calculate the bias of the tree.

The bias was defined as the sum of the depths of all tree nodes.

Given a tree help Ram in finding the bias of the tree. Consider node with value 1 as the root of the tree

And consider the depth of the root node as 0.
*/

#include<bits/stdc++.h>

using namespace std;

int ans = 0;

void DFS(vector<vector<int>>&adj, int depth, int node, int par)
{
    ans += depth;
    for(auto it : adj[node])
    {
        if(it != par)
            DFS(adj, depth + 1, it, node);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++)
    {
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(adj, 0, 1, -1);
    cout << ans << endl;
    return 0;
}