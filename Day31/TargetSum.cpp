/*
Description: Bob and Alice are playing the game of target, in which one player gives other some numbers with a target and the other player has to tell all the possible ways through which he/she can achieve the target using the given numbers. So Bob has given Alice a stream of numbers with a target and asked her to write all the possible ways in which she can form that number. So your task is to help Alice in winning the game.
*/

#include <bits/stdc++.h>
using namespace std;

// vector of vectors for storing the result
vector<vector<int>>result;
// vector for maintaining the result.
vector<int>current;

void func(vector<int>& candidates,int target,int index)
{
    // if the given target is 0 then the maintained result is pushed back.
    if(target==0)
    {
        result.push_back(current);
        return;
    }
    // Base cases.

    if(index==candidates.size() || target<0)
        return;
    
    // pushing back the candidates[index] inside current.
    current.push_back(candidates[index]);
    func(candidates,target-candidates[index],index);
    // backtracking and clearing the vector
    current.pop_back();
    // calling function recursively for the next index.
    func(candidates,target,index+1);      
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    // calling auxilliary function.
    func(candidates,target,0);
    // returning the final result.
    return result;
}

int main() 
{
    // taking inputs
    int target;
    cin>>target;
    int n;
    cin>>n;

    vector<int>candidates(n);

    for(int i=0;i<n;i++)
        cin>>candidates[i];

    vector<vector<int>>ans=combinationSum(candidates,target);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}