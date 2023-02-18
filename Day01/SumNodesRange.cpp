#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: You are given the root of the Binary Search Tree. You are also provided integers start and end.

You have to return the sum of all the nodes that lie in the inclusive range of start and end.

All the values in the tree are unique
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> nodes;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        nodes.push_back(val);  
    }
    int start, end;
    cin >> start;
    cin >> end;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(nodes[i] >= start && nodes[i] <= end)
            sum += nodes[i];
    }
    cout << sum << endl;
    return 0;
}