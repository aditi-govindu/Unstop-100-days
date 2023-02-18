#include <bits/stdc++.h>
using namespace std;

/*
Description: In a shoe factory, left and right shoes are manufactured separately. 
Each shoe has an integral ID attached to it according to the design and size. 
Today, the factory manufactured n left shoes and m right shoes.
All the left and right shoes are put in separate cartons and are sent to Bob, 
who is in charge of making pairs and sending them for final packaging. 
A left shoe can only be paired with another right shoe of the same ID, and 
each shoe cannot be a part of more than one pair. Note: Each carton can have 
more than one shoe with the same ID.
Before Bob starts making pairs, the manager wants to know the IDs of all pairs of shoes that 
will be ready in sorted order so that he can get the boxes printed for final packaging.
*/

int main()
{
    // read inputs
    int n, m;
    cin >> n >> m;
    int left[n], right[m];
    for(int i = 0; i < n; i++)
        cin >> left[i]; 
    for(int i = 0; i < m; i++)
        cin >> right[i];

    // declare map to store frequency of
    // each right shoe
    map<int, int> freq;
    for(int i = 0; i < m; i++)
        freq[right[i]]++;
    
    // declare the result vector
    vector<int> res;
    // iterate through the left shoe array
    for(int i = 0; i < n; i++)
    {
        // if there is a matching right shoe,
        // insert it in the result vector
        // and decrease the frequency of
        // right shoe of the same ID
        if(freq[left[i]] > 0)
        {
            res.push_back(left[i]);
            freq[left[i]]--;
        }
    }
    // sorting the result
    sort(res.begin(), res.end());
    // print the result
    cout << (int)res.size() << endl;
    for(int i: res) cout << i << ' ';
    return 0;
}