#include <bits/stdc++.h>
using namespace std;

/*
Description: Rohit is working in a warehouse. The warehouse is full of boxes that contain items for delivery. The boxes are of 1-meter height are placed one onto the other and arranged in a queue in increasing order of their height such that each pile has a height greater than the previous pile by 2-meters. If we represent the height of piles with the array ‘arr’ of length ‘n’ where ‘n’ is the number of piles then each ith element i.e. arr[i] = (2 * i) + 1 for all valid values of i (i.e., 0 <= i < n). Now owner gave Rohit a task to make all heights of piles equal so that all piles of boxes will be of the same length and easily be shipped in a truck. Rohit wants to make all heights equal in the minimum number of moves. The move is define as – In one operation, Rohit can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). Now help Rohit to find the minimum operation required.
*/

long long minOperations(int n) 
{
	if(n & 1)
    { 
        // Odd Case
		long long N = (n - 1) / 2;  // number of elements before mid element
		return N * (N + 1); 
	}
    // number of elements before mean of mid elements
	long long N = n / 2;  
	return N * N; 
}

int main()
{
    int n ; 
    cin >> n; 
    cout <<  minOperations(n); 
    return 0; 
}