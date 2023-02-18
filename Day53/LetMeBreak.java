import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;

/*
Description: Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
*/

class Solution
{
    public static boolean checkIfCanBreak(String s1, String s2) 
    {
            // for every character in s2 if there exist a char in s1 such that
            // s2.char >= s1.char  or vice versa for the other string return true;
            
            if(s1.length() != s2.length() || s1.length()<=0 || s2.length() <=0) 
                return false;
            char[] s2_char = s2.toCharArray();
            char[] s1_char = s1.toCharArray();
            Arrays.sort(s2_char);
            Arrays.sort(s1_char);
        
            if(s1_char[0] >= s2_char[s2_char.length-1])
                return true;
            if(s2_char[0] >= s1_char[s1_char.length-1])
                return true;
            
            boolean result2 = true,result1=true;
            for(int i=s2_char.length-1 ;i>=0;i--) 
            {
                if(s2_char[i] < s1_char[i])
                    result2=false;
                if(s1_char[i] < s2_char[i])
                    result1=false;
            }
            
            return result2 || result1;
    }

	public static void main (String[] args) throws java.lang.Exception
	{
       Scanner scn  = new Scanner(System.in);
       String str1 = scn.nextLine();
       String str2 = scn.nextLine();
       System.out.println(checkIfCanBreak(str1,str2));
	}
}