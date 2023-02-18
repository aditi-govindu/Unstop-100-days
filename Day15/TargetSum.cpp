/*
Description: Marco is very interested in numbers. His friend Shyam gives him some numbers and a target value to check his knowledge in numbers. He asked him to give the total count of expressions built out of the numbers given by adding one of the symbols '+' and '-' before each integer in numbers and then concatenating all the integers which will be equal to the target value.

Marco got confused with this question and asked you for help.
*/

#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
    unordered_map<int,int> cur({{0,1}}), nxt, *p_cur=&cur, *p_nxt=&nxt;
    for(int i = 0; i < nums.size(); i++) {
        for(auto &p : *p_cur) {		// storing all possible results in unordered_map
            (*p_nxt)[p.first+nums[i]] += p.second; 
            (*p_nxt)[p.first-nums[i]] += p.second;
        }
        swap(p_cur,p_nxt);		// swapping the maps
        p_nxt->clear();
    }
    return (*p_cur)[S];
}

int main() {
    
    vector<int> nums;
    int n,target;
 
	// Taking inputs
	cin >> n;
 
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	
	cin >> target;
 
	cout << findTargetSumWays(nums,target);
 
	return 0;
}