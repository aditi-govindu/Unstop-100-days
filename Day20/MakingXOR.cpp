#include<bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
typedef long long ll;

/*
Description: Ramu the amazing guy has been provided with a problem. He has been given a sequence of numbers in which he has to take the xor of all the subsets of the sequence and sum them up. Your task is to help Ramu in doing that.
*/

int subsetXORSum(vector<int>& nums) 
{
	// for storing result
    int ans=0;
    // looping over the 32 bits
    for(int i=0; i<32; i++)
    {
    	// creating a mask.
        int mask=1<<i;
        // maintaining count
        int count=0;
        for(int j=0; j<nums.size(); j++)
        {
        	// if nums[j]&mask increment the count
            if(nums[j]&mask) count++;
        }
        if(count)
            ans+=mask*(1<<(count-1))*(1<<(nums.size()-count));
    }

    return ans;
}

// driver code for taking inputs
void solve()
{
	int n;
	cin>>n;

	vector<int>arr(n);

	for(int i=0;i<n;i++)
		cin>>arr[i];

	long long ans=subsetXORSum(arr);

	cout<<ans<<endl;
}

int main()
{
	solve();
    return 0;
}