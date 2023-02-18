#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: One day Mary wanted to give a present to her friend, and she decided to give her a beautiful bouquet of flowers, she started collecting the flowers for the bouquet, she exactly needed 2 types of flowers. The total number of flowers should be ‘t’. Now she starts collecting it from her garden. In her garden, there are ‘N’ types of flowers, and each type of flower are arranged in a queue in non-decreasing order, e.g. 1, 3, 6, 15 and so on. Now she wants your help to find which indexes of flowers she should collect.
*/

int main() 
{
    int m, target;
    cin >> m >> target;
    vector<int> flowers;

    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        flowers.push_back(temp);
    }  

    // Find pairs whose sum is equal to target
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = i +1; j < m; j++)
        {
            if(flowers[i] + flowers[j] == target)
            {
                // SInce exactly 1 pair exists, break after display
                cout << i  << " " << j << endl;
                break;
            }
        }
    }
    return 0;
}