/*
Description: Jimmy and George are doing programming. Jimmy loves sorting very much, so to challenge Jimmy’s ability, George gave him two arrays, arr1 and arr2 and asked him to sort the elements of arr1, such that the relative ordering of items in arr1 is the same as in arr2. Elements that do not appear in arr2 should be placed in ascending order at the end of arr1. Now Jimmy is confused, and he needs help. Now your task is to help him to find the new array formed.
*/

#include <bits/stdc++.h>
using namespace std;

 vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
   
      map<int,int> m;
        //mapping values along with their count of appearance
        for(auto i:arr1) m[i]++;
        
        //assigning values to arr1 according to the order given by arr2
        int pos=0;
        for(auto j:arr2){
            while(m[j]-- >0) arr1[pos++]=j;
        }
        
        //for remaining elements which are not a part of arr2
        for(auto it:m){
            while(it.second-- >0) arr1[pos++]=it.first;
        }
        
        return arr1;
        
    }

int main()
{
    int n , m ; 
	cin >> n >> m; 
    vector < int > arr1(n) , arr2(m); 
    for(int i = 0; i < n ; i++)
        cin >> arr1[i]; 
    for(int i = 0 ; i<n; i++) 
        cin >> arr2[i]; 
    vector < int > v = relativeSortArray(arr1 , arr2); 
    for(auto a: v) 
        cout << a << " "; 
	          
	return 0;
}