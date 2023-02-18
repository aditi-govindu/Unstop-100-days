#include <bits/stdc++.h>
using namespace std;

/* Description: Marco likes numbers a lot. His friend gave him an even integer n which initially has a permutation perm of size n​​ where perm[i] == i​ (0-indexed)​​​​.

In one operation, he needs to create a new array arr, and for each i:

If i % 2 == 0, then arr[i] = perm[i / 2].
If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].
and will then assign arr​​​​ to perm.

Help Marco to return the minimum non-zero number of operations he needs to perform on perm to return the permutation to its initial value. */

long long reinitializePermutation(long long n) 
{
    long long cnt=0;
    long long index=1;
    
    do 
    {
        // replacing index position according to even/odd
        if(index & 1) 
            index = n/2 + index/2;	
        else 
            index = index/2;
        cnt++;
    }while(index!=1);	// looping unless it  reaches its initial value
    return cnt;
}

int main() 
{
	long long n;
	cin >> n;
    // Display result
	cout << reinitializePermutation(n);
	
	return 0;
}