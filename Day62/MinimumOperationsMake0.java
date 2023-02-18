import java.util.*;
/*
Description: Given an integer N, the task is to reduce N to 0 in the minimum number of operations using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of N.

Change the ith bit in the binary representation of N if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.

 Print the count of the number of primes less than or equal to the minimum number of operations needed to reduce N to 0.
*/

class DP 
{
	// Convert N to 0
	public static int minimumOneBitOperations(int n, int res)
	{
	
		// Base Case
		if (n == 0)
			return res;

		// Store the highest power of 2 less than or equal to n
		int b = 1;
		while ((b << 1) <= n)
			b = b << 1;

		// Return the result
		return minimumOneBitOperations((b >> 1) ^ b ^ n, res + b);
	}

	 public static int sieveOfEratosthenes(int n) 
     {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) 
        {
            if (prime[p] == true) 
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int count=0;
        for (int i = 2; i <= n; i++) 
        {
            if (prime[i] == true)
                count++;
        }
        return count;
    }


	// Driver Code
	public static void main(String args[])
	{
		// Given Input
        Scanner scn = new Scanner(System.in);
        int N = scn.nextInt();
            
        // Function call
        int ans = minimumOneBitOperations(N, 0);
        System.out.println(sieveOfEratosthenes(ans));
	}
}