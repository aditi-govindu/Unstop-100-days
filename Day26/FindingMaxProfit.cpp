#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Ronnie is given n coins each having some value and provided with a task. In the task Ronnie has to first arrange the coins in a sorted fashion after that he has to set the coins in the form of a tree. After forming the tree he has to find the maximum possible absolute value of the difference in that tree as that will be the profit he will make. Your task is to help Ronnie in finding the max profit.
*/

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    vector<int>coins;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    // Maximum profit on coins is largest denomination - smallest denomination
    int max = *max_element(coins.begin(), coins.end());
    int min = *min_element(coins.begin(), coins.end());
    cout << max - min << endl;

    return 0;
}