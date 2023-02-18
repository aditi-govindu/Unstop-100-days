/*
Description: There is a cricket match between Team A. and Team B. Team A batted first and set a target of n-1 runs. To win the match, Team B has to score exact n-1 runs. You are provided with an array of integers of length n. The ith value of the array represents the maximum run team B can score on the ith ball. The number of balls played by team B is always equivalent to runs scored by team B.

Select only those balls with the help of which you can reach the target.

 Your task is to return the Boolean value. If Team B can reach that target, then return true and if not, then return false.
*/

import java.util.*;

public class Solution 
{
    public static void main(String[] args) throws Exception 
    {
        Scanner sc =  new Scanner(System.in);
        int n =  sc.nextInt();
        int[]  arr =  new int[n];
        for(int i = 0; i<n; i++)
            arr[i] =  sc.nextInt();
        boolean ans =  result(arr);
        System.out.println(ans);
    }

    public static boolean result(int[] nums) 
    {
        boolean[] ans =  new boolean[nums.length];
        ans[nums.length-1] = true;
        for(int i = nums.length-2; i>=0; i--)
        {
            int c = 0;
            for(int j = 1; j+i<nums.length && j<=nums[i]; j++){
                if(ans[j+i] ==  true)
                {
                    c++;
                    ans[i] = true;
                    break;
                }
            }
            if(c == 0)
                ans[i] =  false;
        }
        return ans[0];
    }
}