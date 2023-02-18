#include <bits/stdc++.h>
using namespace std;

/*
Description: Alice’s mom bought n bags of chocolates numbered from 1 to n. The ith bag (1 <= i<= n) has ai chocolates. Alice wants to share some of the chocolate bags with Bob such that both of them get an equal number of chocolates, but she is not able to divide them in such a way. Now, she wonders if it is even possible to do so. Help Alice find out if the bags can be divided between her and Bob such that both of them get an equal number of chocolates.
*/

int main(){
    // read inputs
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    int totalSum = 0;

    // find sum of all array elements
    for (int i : a) {
        totalSum += i;
    }
    // if totalSum is odd, it cannot be partitioned into equal sum subset
    if (totalSum % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    int subSetSum = totalSum / 2;

    // dp[i][j] represents if the sum of j can be obtained using
    // elements from 1 to i of the array or not
    vector<vector<bool>> dp(n+1, vector<bool> (subSetSum + 1, false));
    
    // if no element is used, the sum will always be 0
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= subSetSum; j++) {
            // if the current element is greater than the
            // required sum, the sum can only be obtained
            // using previous elements
            if (j < a[i - 1])
                dp[i][j] = dp[i - 1][j];
            // otherwise, the sum j can be obtained either by including
            // the current element or excluding it
            else
                dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - a[i - 1]]);
        }
    }

    // dp[n][subSetSum] will represent the required answer
    if(dp[n][subSetSum]){
        cout << "YES" << endl;
    }else{
        cout << "NO" <<endl;
    }

    return 0;
}