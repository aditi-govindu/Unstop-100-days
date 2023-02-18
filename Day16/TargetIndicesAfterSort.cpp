#include <bits/stdc++.h>
using namespace std;

/*
Description: Marco likes numbers a lot. His friend Shyam gives him some numbers and a target value and asks him to tell the indices of the sorted numbers where the target value will match with that element. Help Marco to solve this crazy problem
*/

void targetIndices(vector<int> &nums, int target) {
    vector<int> output;
    int count=0;
    int tCount=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] < target)
        {	// counting the number of elements that are less than the target value
            count++;
        }
        else if(target == nums[i])
        {	// counting the number of elements which are equal to the target value
            tCount++;
        }
    }
    for(int i=0;i<tCount;i++)
    {
        output.push_back(count++);
    }
	 
	 cout << output.size() << "\n";
	 for(int i=0;i<output.size();i++) cout << output[i] << " ";
	 
	 return ;
}

int main() {
	int n,target;
	vector<int> Input;
	// Take inputs
	cin >> n;
	
	for(int i=0;i<n;i++) 
    {
		int x;
		cin >> x;
		Input.push_back(x);
	}
	
	cin >> target;
	
	targetIndices(Input, target);
	
	return 0;
}