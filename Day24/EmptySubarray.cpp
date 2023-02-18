/*
Description: Polycarp was learning a new data structure called an array. He found that arrays are a continuous allocation of the same type of data. He later began playing with different integer arrays. He was solving problems involving integer arrays from a famous problem portal on the internet when he got stuck on a problem. He approached you for help.

You are given an array, you need to find the number of empty subarrays in the given array. An empty subarray is defined as a non-empty array whose sum is zero.

Help Polycarp in solving the problem.
*/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0; i<n; i++)
      cin>>arr[i];

   int cnt = 0;
   unordered_map<int,int> mp; //map to store the prefix sum 
   mp[0]++; //storing the sum of empty array
   int pref = 0; //for calculation of the prefix
   for(int i=0; i<n; i++)
   {
      pref += arr[i]; 
      if(mp.count(pref)) //if previous pref existed means there exists a subarray whose sum is 0
         cnt += mp[pref]; //incrementing the number of such subarrays
      mp[pref]++; //hashing the current value of prefix
   }
   cout<<cnt<<endl; //printing the ans
   return 0;
}