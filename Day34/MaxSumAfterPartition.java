/*
Description: Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Calculate the largest sum of the given array after partitioning. Let this value be m. Display all the prime numbers less than or equal to m.

Test cases are generated so that the answer fits in a 32-bit integer.
*/

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;

class Solution
{
     public static int maxSumAfterPartitioning(int[] arr, int k) 
     {
        int[] dp = new int[arr.length];
        for (int i = 0; i < dp.length; i++) 
        {
            int currMax = 0;
            for (int j = 1; j <= k && i - j + 1 >= 0; j++) 
            {
                // Store any combination of k maximum values in array
                currMax = Math.max(currMax, arr[i - j + 1]);
                int rightSub = currMax * j;
                if (i - j < 0) 
                    dp[i] = Math.max(dp[i], rightSub);
                else 
                    dp[i] = Math.max(dp[i], dp[i - j] + rightSub);
            }
        }
        return dp[arr.length - 1];
    }

    public static int sieveOfEratosthenes(int n) 
    {    
        // Find all prime numbers in range 1 to n
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
        int count = 0;
        
        for (int i = 2; i <= n; i++) 
        {
            if (prime[i] == true)
                count++;
        }
        return count;
    }
    
    
	public static void main (String[] args) throws java.lang.Exception
	{
        Scanner scn  = new Scanner(System.in);
        int n = scn.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++)
            arr[i] = scn.nextInt();

        int k =scn.nextInt();
        int res = maxSumAfterPartitioning(arr,k);
        System.out.println(sieveOfEratosthenes(res));
     
	}
}