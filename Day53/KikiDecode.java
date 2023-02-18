import java.util.*;
import java.lang.*;
import java.io.*;

/*
Description: Kiki is given an encoded string. She has to decode the string and display the number of primes less than or equal to the number of the characters in the decoded string.The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.Help kiki decode the string and thus calculate the primes less than or equal to the number of characters in the decoded string.
*/

class Solution
{
	static int index;
    public static String decodeString(String s) 
    {
        index = 0;
        return recursion(s, new StringBuilder()).toString();
    }
    
	public static StringBuilder recursion(String s, StringBuilder result) 
    {
        int count = 0;    

        while (index < s.length()) 
        {   
            // Push to stack till ] is read
            if (s.charAt(index) == ']')
                return result;
            else if (Character.isDigit(s.charAt(index))) 
            {
                // If number is seen, stack length * number is added to length
                String countString = "";
                while (Character.isDigit(s.charAt(index))) 
                {
                    countString += String.valueOf(s.charAt(index));
                    index++;
                }
                count = Integer.parseInt(countString);
                continue;
                
            } 
            else if (s.charAt(index) == '[') 
            {
                // Append letters to stack
                index++;
                StringBuilder substring = recursion(s, new StringBuilder());
                for (int j = 0; j < count; j++)
                    result.append(substring);
            } 
            else
                result.append(s.charAt(index));
            index++;
        }
        return result;
    }

    // Find prime numbers in given range
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
     
    public static void main(String[] args) 
    {
        Scanner scn = new Scanner(System.in);
        String s  = scn.nextLine();
        String ans = decodeString(s);

        int primeslessorequal = ans.length();
        System.out.println(sieveOfEratosthenes(primeslessorequal));
    }
}