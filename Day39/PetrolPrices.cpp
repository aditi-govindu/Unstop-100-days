#include <bits/stdc++.h>
using namespace std;

/*
Description: Startled by the recent instability in petrol prices, Harsh decided to find out the pattern to buy petrol when it is cheapest. To do so, he collected the data of petrol prices over the last n days. While decoding the pattern, he gets stuck and asks for your help.

Given the petrol prices from day 1 to n, for each day, Harsh wants you to find out the minimum number of days after which the petrol price is strictly higher than the current day. If there is no future day for which this is possible, let the answer for that day be 0.
*/

int main(){
    // read inputs
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i:a) cin >> i;

    // initialize the dp array and maximum 
    // element found so far
    vector<int> dp(n);
    int max_price = 0;

    // iterate through the array backwards
    for(int i = n -1; i >= 0; i--){

        // if there is no element greater than a[i]
        // to its right, dp[i] will be 0
        if(a[i] >= max_price){
            dp[i] = 0;
            max_price = a[i];
            continue;
        }

        // otherwise, dp[i] will be atleast 1
        int ans = 1;
        // use the previously computed values
        // of the dp array to find dp[i]
        while(a[i+ans] <= a[i]){
            ans += dp[i+ans];
        }
        // set dp[i] to the computed answer
        dp[i] = ans;
    }
    
    // print the final answer
    for(int i: dp)
        cout << i << ' ';
    
    return 0;
}