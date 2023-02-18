/*
Description: Mocha is given yet another task. 
In the task mocha is provided with a sequence of n numbers. 
In the sequence for every number we have to find the count of elements that 
are strictly smaller than it and generate a sequence from it. 
Your task is to help mocha in building the sequence.
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
typedef long long ll;


// function for execution
vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
{
        // finding size of nums
        int n = nums.size();
        // creating bucket of size 102
        int bucket[102] = {0};

        // looping through nums
        for(auto i:nums)
            bucket[i+1]++;

        // filling up bucket vector
        for(int i=1;i<102;i++)
            bucket[i] += bucket[i-1];

        // filling up nums
        for(int i=0;i<n;i++)
            nums[i] = bucket[nums[i]];

        // returning
        return nums;
}


// driver code for execution
int main()
{
    
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int>ans=smallerNumbersThanCurrent(arr);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

     return 0;
}