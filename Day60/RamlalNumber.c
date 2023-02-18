#include <bits/stdc++.h>
using namespace std;

/*
Description: Ramlal was living in a village where there was many students which where studying one day he thought to give a work to students to return an array of all the integers that appear twice from an integer array nums of length n, where all the integers in nums are in the range [1, n], and each integer appears once or twice.
*/

vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int> ans;
    unordered_set<int> seen;

    for (auto& num : nums) 
    {
        // Store unique numbers, if count greater than 1 display it
        if (seen.count(num) > 0)
            ans.push_back(num);
        else
            seen.insert(num);
    }

    return ans;
}
    
    
int main() 
{
    int n;
    cin>>n;
    
    
    vector<int> a(n);
    
    for(auto &x : a) cin>>x;
    
    vector<int> ans = findDuplicates(a);
    
    sort(ans.begin(),ans.end());
    for(auto x: ans)
        cout<< x <<" ";
    cout<<endl;
}