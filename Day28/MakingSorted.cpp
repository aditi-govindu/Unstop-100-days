#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
Description: Ram loves Binary search trees. They have a special property that all the 
values less than node lies to the left of it and all the greater values lie to the right of it. 
So he has been provided with two BSTs one containing n and the other having m nodes. 
His task is to make a sorted sequence out of the values present in the two trees. Help Ram in making the sequence.
*/

using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n;
    vector<int> tree;

    // Accpet tree values from user
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }
    // Sort the array
    sort(tree.begin(), tree.end());

    // Display final results to user
    for(int i = 0; i < tree.size(); i++)
        cout << tree[i] << " ";
    return 0;
}