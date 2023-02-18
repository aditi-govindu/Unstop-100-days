#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: N friends are given tasks at various times, all have different efficiencies, 
so they finish the tasks at different times. To do the task all have to enter into a big room. 
The person who assigned the task will come once in a day to check and will report how 
many people were there in the room when he gave the task. Find what the person will report.
NOTE→ Time is assumed to be an integer variable that takes the value 0 to 86400.
*/

int main() 
{
    int n, inspect;
    cin >> n;

    vector<int> started(n);
    vector<int> completed(n);

    // Store starting time
    for(int i = 0; i < n; i++)
        cin >> started[i];

    // Store end time
    for(int i = 0; i < n; i++)
        cin >> completed[i];
    
    // Time when person comes in
    cin >> inspect;
    
    int working = 0;
    for(int i = 0; i < n; i++)
    {
        // If inspector comes at time in start and end time, count person working
        if(started[i] <= inspect && completed[i] >= inspect)
            ++working;
    }
    
    // Display results to user    
    cout << working;
    return 0;
}