#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Each Christmas, the members of the royal family exchange gifts with each other. The family has n members numbered from 1 to n. However, not everyone in the family gives and receives the same number of gifts.

The youngest member receives a gift from everyone else in the family except himself but does not give any gifts to anyone else. This Christmas, there were a total of m gifts that were exchanged among the family members. You are provided with the data for all m gifts. Find the number that represents the youngest family member using the given data.
*/

int main() 
{
    int m, n;
    cin >> n;
    cin >> m;
    int arr[m][2];

    for(int i = 0; i < m; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 1; i <= n; i++)
    {
        int received = 0;
        int gave = 0;
        // COunt no. of gifts every person gave and received
        for(int j = 0; j < m; j++)
        {
            if(arr[j][0] == i)
                gave++;
            if(arr[j][1] == i)
                received++;
        }
        // Youngest person will receive n-1 gifts and give none
        if(received == n-1 && gave == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    // No youngest member found
    cout << -1 << endl;
    return 0;
}