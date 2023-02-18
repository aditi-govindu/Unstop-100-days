/*
Description: John and Jimmy are doing programming. Jimmy loves mathematics very much, so to challenge Jimmy’s ability, John told him to perform XOR operation on elements of array. John gave him a sorted array ‘nums’ of n non-negative integers and an integer ‘maximumBit’ and told Jimmy to perform the following query n times:

Find a non-negative integer k < 2^(maximumBit) such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Jimmy is not good at coding, and she needs help. Now your task is to help him to find the new answer array formed
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
{
    int n = nums.size(), XOR = 0;    //Decalred variable n with size of array and xor with 0;
	vector<int> ans(n);
	for(auto& num : nums) XOR ^= num;   //  Interating the array.
	ans[0] = XOR ^= (1 << maximumBit) - 1;  // 2^maximumBit - 1
	for(int i = 1; i < n; i++) ans[i] = XOR ^= nums[n - i];            
	return ans; //return answer
}

int main()
{
    int n,maximumBit;   //declared variable.
    cin>>n>>maximumBit; 
    vector<int>nums;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        nums.push_back(x);  //Insert elements into vector.
    }
    vector<int>ans=getMaximumXor(nums,maximumBit);
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";  //print answer for each query.
    return 0;
}