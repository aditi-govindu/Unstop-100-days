#include<bits/stdc++.h>
using namespace std;

/*
Description: Saurav and Vikas have just now read about the celebrity problem, and vikas was just learning about the simplicity that hashmap provides over other data structures. So vikas wants to solve the celebrity problem using hashmap. Help him solve the statement given below.

There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
*/

int findCenter(vector<vector<int> >& edges) 
{
    map<int, int> m;
    for(auto edge : edges){
        m[edge[0]]++;
        m[edge[1]]++;
    }
    int ans = -1, maxVal = 0;
    for(auto it : m){
        if(it.second > maxVal){
            ans = it.first;
            maxVal = it.second;
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<vector<int> > v(n);
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        v[i].push_back(x);
        v[i].push_back(y);
    }
    cout<<findCenter(v)<<endl;
    return 0;
}