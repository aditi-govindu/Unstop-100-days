#include<bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
typedef long long ll;

/*
Description: John operates in a coin factory with n coins ranging from low-limit to high-limit inclusive (i.e., n == high limit - low limit + 1) and an infinite number of boxes ranging from 1 to infinity. He has been provided with n numbers in which low and high is present. Low is the lowest in the n numbers and high is the maximum in those coins.

At this factory, your task is to put each coin in a box with a number equal to the total of the coin's digits. The coin number 321, for example, will be placed in the box 3 + 2 + 1 = 6, whereas the coin number 10 will be placed in the box 1 + 0 = 1.

Your task is to find the low and high in the numbers and return the number of coins in the box with the most coins, given two integers low-limit and high-limit.
*/

int countBalls1(int lowLimit, int highLimit) 
{
    // creating 46 sized count array
    int cnt[46] = {};
    // looping from lowLimit to highLimit
    for (auto i = lowLimit; i <= highLimit; ++i) 
    {
        // sum variable for calculating the sum
        int sum = 0, n = i; 
        // summing up the digits
        while(n) {
            sum += n % 10;
            n /= 10; 
        }
        // incrementing the cnt[sum]
        ++cnt[sum];
    }
    // returning the max element from cnt vector
    return *max_element(begin(cnt), end(cnt));
}


int countBalls(vector<int>& arr)
{
    // sorting the arr vector
    sort(arr.begin(),arr.end());
    // finding low and high
    int low=arr[0],high=arr[arr.size()-1];
    // returning answer
    return countBalls1(low,high);
}

// driver function of inputs
void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
    cout<<countBalls(arr)<<endl;
    return;
}

int main()
{
    solve();
    return 0;
}