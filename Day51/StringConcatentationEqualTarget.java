/*
Description: Given an array of digit strings nums and a digit string target,  return the number 
of pairs of indices (i, j) (where i!= j) such that the concatenation of nums[i] + nums[j] equals target.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
	public static int numOfPairs(String[] nums, String target) 
    {
        // Store string and count of occurences
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i<nums.length; i++)
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1 );
        
        int ans = 0, n = target.length();
        String a = "", b= "";
        for (int i = 1; i<n; i++)
        {
            a = target.substring(0, i);
            b = target.substring(i, n);
            if (map.containsKey(a) && map.containsKey(b))
            {
                if (a.equals(b)) 
                    ans += (map.get(a) * (map.get(a)-1));
                else 
                    ans+= (map.get(a) * map.get(b));
            }
        }
        return ans;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		String[] arr = new String[n];

		for(int i = 0; i < arr.length; i++)
			arr[i] = scn.next();

		 String target = scn.next();
		 System.out.println(numOfPairs(arr , target));
	}
}