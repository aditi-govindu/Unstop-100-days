/*
Description: Ram has an array of length n, he want to find majority elements in it.

Help him find the majority entry from an array.

The majority element is the one that appears n / 2 times or more. 
You can take it for granted that the majority member is always present in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n; 
  cin >> n;
  int nums[n];

  for(int i = 0; i < n; i++)
    cin >> nums[i];

  int x = 0, count = 0;
      
  for(int i=0; i<n; i++)
  {
      // Voting algorithm where first element is candidate
    if(count == 0)
      x = nums[i];
    // If next is equal to current, increase count else decrement count
    count += ((nums[i] == x) ? 1 : -1);
  }
  
  cout << x << "\n";  
  return 0;
}