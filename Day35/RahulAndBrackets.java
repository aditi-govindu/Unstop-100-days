/*
Description: Rahul is given a string consisting of parentheses, either ‘(‘ or ‘)’ .

The string is said to be valid if

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
In one move, Rahul can insert a parenthesis at any position of the string.

For example, if s = "()))", he can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Let the minimum number of moves required to make s valid be m. 
Return the number of primes less than or equal to m.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution 
{
    // Sieve of Erasthoneses
    public static int countPrimes(int n) 
    {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        // Count prime numbers in range of [2,n]
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

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int brackets = 0;
        Stack<Character> st = new Stack<>();
        // Count closing brackets
        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s.charAt(i);
            if (ch == '(') 
                st.push(ch);
            else 
            {
                if (st.size() > 0 && st.peek() == '(') 
                    st.pop();
                else 
                    st.push(ch);
            }

        }
        // Display results to users
        brackets = st.size();
        System.out.println(countPrimes(brackets));
    }
}
