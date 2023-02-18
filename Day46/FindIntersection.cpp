#include <bits/stdc++.h>
using namespace std;

/*
Description: Ronak is starting to understand linked lists now, and is now looking at improving on some classical linked list problems. At this moment he is working on finding the intersection point of two linked lists. He has no idea how he can approach this problem, help him solve this problem.

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
*/
  
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
{
    vector<vector<int>> v;
    int i=0,j=0;

    while(i<A.size() && j<B.size())
    {
        int l=max(A[i][0], B[j][0]);
        int u=min(A[i][1], B[j][1]);

        // Lower limit is minimum of values
        if(l<=u) 
            v.push_back({l,u});
        if(A[i][1] < B[j][1])   
            i++;
        else 
            j++;
    }
    return v;
}

int main() 
{ 
    int m, n;
    cin>>n;
    vector<vector<int>> first;
    for(int i=0; i<n; i++)
    {
        vector<int> temp(2);
        for(int j=0; j<2; j++)
            cin>>temp[j];
        first.push_back(temp);
    }
    cin>>m;
    vector<vector<int>> second;
    for(int i=0; i<m; i++){
        vector<int> temp(2);
        for(int j=0; j<2; j++){
            cin>>temp[j];
        }
        second.push_back(temp);
    }
    vector<vector<int>> result;
    result = intervalIntersection(first, second);
    for(int i=0; i< result.size(); i++){
        for(int j=0; j<2; j++){
            cout<<result[i][j]<<" ";
        }
    }
    return 0; 
}