#include<bits/stdc++.h>

using namespace std;
/*
Description: You are given an array of votes each student has got in the student election in your university. You have to find the subsequence of votes of the students who can form majority to run the student association.

A majority is formed when the students have strictly received more than half of the total votes polled.

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.
*/
vector<int>majority_find(vector<int>&nums) 
{
    vector<int>res, freq(101, 0);

    //we will create an result and a frequency vector to store the result

    //and frequency to find out the largest element.

    int sumres=0, sumleft=accumulate(begin(nums), end(nums), 0);

    //STL function that would calculate the total sum.

    for(auto n: nums)

        freq[n]++;//store the frequency of each unique element.

    for(int n=100; n>=1; n--)
    {
        while(freq[n]-->0&&sumres<=sumleft/*break the loop when result sum crosses left sum*/ )
        {

            sumres+=n;//calculating result sum.

            sumleft-=n;//deducting the ans from total sum

            res.push_back(n);

        }

    }
    return res;//returning the result
}


int main()
{

    int n,temp;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        //taking input
        cin>>temp;
        nums[i]=temp;

    }

    //calling the function that would solve the problem
    auto ans=majority_find(nums);

    //printing the output
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;

}