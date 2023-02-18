import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/

class Solution 
{
    // Reverse the string
    public static String reverseString(String str)
    {
        StringBuilder sb = new StringBuilder(str);
        sb.reverse();
        return sb.toString();
    }

    static String palindrome(String[] words, int n)
    {
        
        for(int i = 0; i < n; i++)
        {
            String rev = reverseString(words[i]);
            // Check if string is equal to its reverse
            if(words[i].equals(rev))
            {
                return words[i];
            }   
        }
        return "";
    }

    public static void main(String[] args) 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String wrds[] = new String[n];

        for(int i = 0; i < n; i++)
        {
            wrds[i] = sc.next();
        }

        String ans = palindrome(wrds, n);
        System.out.println(ans);
    }
}