#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
Description: A machine could be fed with queries of type (a,b).

Where (a b) means we have a number ‘b’ ‘a’ times.

Output the absolute difference between the number that appears most number of times and least number of times (least number of times must be atleast once).
*/

int main() 
{
    int q; 
    cin>>q;
	map<int,int>mp;

	while(q--)
    {
        // Hashmap of count -> value
		int a,b; 
        cin>>a>>b;
		mp[b]+=a;
	}

	int highest_freq = 0; 
    int lowest_freq = 100001;
	int reqnum_1 = 0; 
    int reqnum_2 = 0;

	for(auto it:mp)
    {
        // Store maximum appearing element
		if(highest_freq < it.second){
			highest_freq = it.second;
			reqnum_1 = it.first;
		}
        // Store minimum appearing element
		if(lowest_freq> it.second){
			lowest_freq = it.second;
			reqnum_2 = it.first;
		}
	}
    // Final result is absolute difference of min and max
	cout<<abs(reqnum_1-reqnum_2)<<endl;
}