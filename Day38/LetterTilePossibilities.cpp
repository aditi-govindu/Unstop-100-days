#include <bits/stdc++.h>
using namespace std;

/*
Description: Marco is fond of stickers. He has a lot of stickers on which alphabets in uppercase are printed. He is curious about how many different types of non-empty unique strings or words he can form by using the stickers.
*/

long long numStickersPossibilities(string Stickers) {
    map<char, long long> count;           // Count of individual characters
    for(char c: Stickers) {
        count[c]++;
    }
    
    vector<long long> unique;        // Take only characters which appears at least once in the input string
    long long maxCount = 0;
    
    for(auto it: count) {
        unique.push_back(it.second);
        maxCount = max(maxCount, it.second);
    }
    
    long long n = Stickers.size();

    vector<vector<long long>> ncr(n+1,vector<long long>(maxCount+1,0));     // nCr calculate
    for(int i = 0; i <= n; i++) {
        ncr[i][0] = 1;
        for(int j = 1; j <= maxCount && j <= i; j++) {
            ncr[i][j] = ncr[i-1][j-1]+ncr[i-1][j];        // nCr = (n-1)C(r-1) + (n-1)Cr
        }
    }
    
    vector<long long> dp(n+1,0);                      // Calculate for all lengths
    dp[0] = 1;
    for(int c : unique) {
        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= i && j <= c; j++) {
                dp[i] += dp[i-j]*ncr[i][j];
            }
        }
    }
    // even though above three nested loops seem n^3 but first loop and third loop depends on each other. 
    // Total n iterations will happens combine of those two loops
    // So complexity is n^2
    
    long long answer = 0;
    for(int i = 1; i <= n; i++) {
        answer += dp[i];
    }
    
    return answer;
}

int main() {
	string Stickers;
	
	// taking the inputs
	cin >> Stickers;
	
	cout << numStickersPossibilities(Stickers) << "\n";
	
	return 0;
}