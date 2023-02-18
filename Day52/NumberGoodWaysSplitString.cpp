#include <bits/stdc++.h>
using namespace std;

/*
Description: Marco likes strings a lot. His friend gave him a string s and tell that, a split is called good if he can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.

He asked Marco to return  the number of good splits he can make in s.
*/

int numSplits(string s) {
        
    int ans = 0, count = 0;
    vector<bool> prefix(256,false);
    vector<bool> sufix(256,false);
    vector<int> left(s.size()+1), right(s.size()+1);
    
    for(int i=0;i<s.size();i++) 
    {	
        // finding the prefix unique sum from left side
       if(prefix[s[i]]==false) 
       {
           count++;
           prefix[s[i]] = true;
       }
       left[i]=count;
    }
    
    count=0;
    
    for(int i=s.size()-1;i>=0;i--) 
    { 
        // finding the prefix unique sum from right side
       if(sufix[s[i]]==false) {
           count++;
           sufix[s[i]] = true;
       }
        right[i] = count;
    }
    
    for(int i=0;i<left.size()-2;i++) 
    {	
        // checking what two substrings match the conditions
        if(left[i]==right[i+1])
        ans++;
    }
    
    return ans;
}

int main() {
	string s;
	// take input
	cin >> s;
	
	cout << numSplits(s);
	
	return 0;
}