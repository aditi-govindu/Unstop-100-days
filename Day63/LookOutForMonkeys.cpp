#include <bits/stdc++.h>
using namespace std;
/*
Description: On a long straight road, there are n poles of different heights. A monkey is sitting on the top of each pole, facing towards the direction of the last pole. A monkey can see another monkey sitting in front of it if the heights of all the poles between them are strictly less than the heights of both of their poles.

Find the number of monkeys that each monkey can see sitting on top of his pole.
*/

int main()
{
    // read inputs
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &i: a) 
        cin >> i;

    // vector to store result
    vector<int> ans(n, 0);
    stack<int> s;

    for(int i = n - 1; i >= 0; i--)
    {
        // Last array element = End of stack
        if(!s.empty())
        {
            // all the elements on top of stack
            // that are less than a[i] can be
            // seen
            while(!s.empty() && s.top() < a[i])
            {
                s.pop();
                ans[i]++;
            }
            // if there is an element greater than
            // a[i], it can also be seen
            if(!s.empty())
                ans[i]++;
        }
        // push the current element into the stack
        s.push(a[i]);
    }

    // print the answer
    for(int i: ans)
        cout << i << ' ';
    return 0;
}