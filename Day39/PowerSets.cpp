#include <bits/stdc++.h>
using namespace std;
/*
Description: You are given an integer array nums of unique elements, return all possible power sets. (All subsets).
The solution set must not contain duplicate subsets. Print the solution in any order.
*/

// 2-D vector for storing all the subsets
vector<vector<int>> ans;
    
void solve(vector<int> &nums, int i, vector<int> temp)
{
    if(i==nums.size())
    {
        ans.push_back(temp);
        return;
    }
    // Bactrack if current combination has been explored
    solve(nums, i+1, temp);
    temp.push_back(nums[i]);
    solve(nums, i+1, temp);
}

void subsets(vector<int>& nums) 
{
    vector<int> temp;       
    solve(nums, 0, temp);
}

signed main() 
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    subsets(nums);

    for(auto &i : ans)
    {
        for(auto &j : i)
            cout<<j<<" ";
        cout<<endl;
    }
}