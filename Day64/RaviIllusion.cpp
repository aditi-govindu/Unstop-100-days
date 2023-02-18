#include<bits/stdc++.h>
using namespace std;

/*
Description: Ravi learnedabout the array data structure, and then he learnt about subarrays. He studied that there are multiple different subarrays possible in an array.

His Mom gave him a problem to solve that problem and learn about subarrays in depth.

She defined the illusion of the array as the sum of the minimums of all possible subarrays in an array.

Ravi needs your help to solve this problem.

Given an array, calculate the illusion of the array.

Since the answer can be too large output it modulo (109 + 7).
*/

const int mod = 1e9 + 7;

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n); 
  for(int i=0; i<n; i++)
    cin>>arr[i];

  int left[n], right[n]; //to store previous smaller element index and next smaller element index
  stack<int> st; //stack for building previous smaller element

  for(int i=0; i<n; i++)
  {
      //while current element is smaller than the element on stack top keep popping
        while(!st.empty() && arr[st.top()] > arr[i]) 
            st.pop();
        if(st.empty()) 
            left[i] = -1;
        else left[i] = st.top();
        st.push(i); //finally push the current index in the stack
  }

  stack<int> st1; //stack for building the next smaller element
  for(int i=n-1; i>=0; i--)
  {
    while(!st1.empty() && arr[st1.top()] >= arr[i]) 
      st1.pop();
    if(st1.empty()) right[i] = n;
    else right[i] = st1.top();
    st1.push(i);
  }

  long long int ans = 0; //for storing the final ans
  for(int i=0; i<n; i++)
  {
    int leftel = i - left[i]; //length of the longest subarray on the left of the current element
    int rightel = right[i] - i; //length of the longest subarray on the right of the current element 
    ans = (ans + (arr[i]*leftel*rightel)%mod)%mod;
  }
  cout<<ans<<endl;
}