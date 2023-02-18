#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: There are many apple trees in the garden. The garden owner has to sell apples in the market, so he wants to collect all the apples. He has a basket with the capacity ‘C’ to collect the apples from the trees. The trees are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith tree is located at x = i. the man is at x = -1 position, where he has big storage available for storing the apples. He will collect the apples in the following way:

Collect the apple from the tree in order from left to right.
After collecting from the current tree, if the basket does not have enough capacity to fill the next tree apples, he will return to his initial point, place all his apples there, and come back to collect from here.
He is initially at the initial point (i.e., x = -1). It takes one step to move one unit on the x-axis.

Now your task is to find the number of steps he will take to collect the last apple.
*/

int main() 
{
    int tr, capacity;
    cin >> tr >> capacity;

    vector<int> trees(tr);

    for(int i = 0; i < tr; i++)
        cin >> trees[i];
    
    int remaining = capacity;
    long long steps = 0;
    
    for(int i = 0; i < tr; i++)
    {
        // Basket overflows, go back to start and empty the basket
        if(trees[i] > remaining)
        {
            remaining = capacity;
            steps += (2*i);
        }
        // Add apples to basket and go ahead
        remaining -= trees[i];
        steps++;
    }
    cout << steps;
    return 0;
}