#include<bits/stdc++.h>
using namespace std;
/*
Description: John was learning arrays data structure when his friend Ram arrived. Seeing John, Ram thought of a challenge for John. He challenged him to calculate the measurement of the array.

Given a 0 indexed array Ram defined the measurement of the array as the sum of sanities of all the elements in the array. The sanity of an element in the array was defined as the sum of its index and the index of its last occurrence in the array.

Note that duplicate elements may exist in the array.

Given an array, your task is to help John in calculating the measurement of the array. Since the output may be too large therefore print it modulo 1000000007.
*/

const int mod = 1e9 + 7;

int last_occurence(vector<pair<int,int>>&arr, int el) 
{
    // Binary search to find last occurrence
    int lo = 0;
    int hi = arr.size()-1;
    int ans = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        if(arr[mid].first <= el)
        {
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ans; //returning the last index 
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        arr.push_back({k, i});
    }
    sort(arr.begin(), arr.end()); //sorting the array
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int sanity = arr[i].second + last_occurence(arr, arr[i].first);
        ans = (ans + sanity)%mod; //adding the contribution of the current element 
    }
    cout<<ans<<endl;
    return 0;
}