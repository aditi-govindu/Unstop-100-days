#include <bits/stdc++.h>
using namespace std;

/*
Description: Marco is very interested in numbers. His friend Shyam gives him an array of numbers and a target value and asks him the number of subarrays whose sum will be equal to the target value.

Marco got confused and asked you to help him.
*/

int subarraySum(vector<int>& arr, int k) 
{
    int n = arr.size(); // take the size of the array
    
    int prefix[n]; // make a prefix array to store prefix sum
    
    prefix[0] = arr[0]; // for element at index at zero, it is same
    
    // making our prefix array
    for(int i = 1; i < n; i++) {
        prefix[i] = arr[i] + prefix[i - 1];
    }
    
    unordered_map<int,int> mp; // declare an unordered map
    
    int ans = 0; // to store the number of our subarrays having sum as 'k'
    
    for(int i = 0; i < n; i++) 
    {	
        // traverse from the prefix array
        if(prefix[i] == k) // if it already becomes equal to k, then increment ans
            ans++;
        
        // now, as we discussed find whether (prefix[i] - k) present in map or not
        if(mp.find(prefix[i] - k) != mp.end()) {
            ans += mp[prefix[i] - k]; // if yes, then add it our answer
        }
        
        mp[prefix[i]]++; // put prefix sum into our map
    }
    
    return ans; // and at last, return our answer
}

int main() {
	//  Taking the inputs
	int n,x,target;
	vector <int> input;
	
	cin >> n;
	
	for(int i=0;i<n;i++) {
		cin >> x;
		input.push_back(x);
	}
	
	cin >> target;
	
	cout << subarraySum(input,target);
	return 0;
}