#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Given an array of prices, where prices[i] represent the price of the ith item in a store. If you buy the ith item in the shop, you will receive a discount equivalent to prices[j], where j is the minimum index such that j >i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Print an array with the ith element representing the final price you will pay for the ith item in the shop after considering the special discount.
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> prices;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        prices.push_back(temp);
    }
    vector<int> final_prices;

    for(int i = 0; i < n; i++)
    {
        // Assume no discount
        int finalcost = prices[i];
        for(int j = i+1; j < n; j++)
        {
            // Apply discount to item i
            if(prices[j] <= prices[i])
            {
                finalcost = prices[i] - prices[j];
                break;
            }
        }
        final_prices.push_back(finalcost); 
    }

    for(int i = 0; i < n; i++)
    {
        cout << final_prices[i] << " ";
    }
    return 0;
}