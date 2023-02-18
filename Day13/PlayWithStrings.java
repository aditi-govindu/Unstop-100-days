import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Description: Krishna gives two strings, word1 and word2, to his two friends. They start with word1 and merge the strings by adding letters in alternating sequence. Append the additional letters to the end of the combined string if one string is longer than the other.

Krishna told his friends to to return the combined string
*/

class Solution {
    public static String merged(String w1, String w2, int len1, int len2)
    {
        String result = "";
        int i = 0;
        // If word1 is smaller than word 2, overlap letters till length of word1 is exhausted
        if(len1 < len2)
        {
            for(i = 0; i < len1; i++)
                result = result + w1.charAt(i) + w2.charAt(i);
            // Copy remaining word2
            for(int j = i; j < len2; j++)
                result += w2.charAt(j);
        } 
        // If word2 is smaller than word1, overlap letters till length of word2 is exhausted
        else if(len2 < len1)
        {
            for(i = 0; i < len2; i++)
                result = result + w1.charAt(i) + w2.charAt(i);
            // Copy remaining word1
            for(int j = i; j < len1; j++)
                result += w1.charAt(j);
        }
        else
        {
            // word1 and word2 of equal length
            for(i = 0; i < len1; i++)
                result = result + w1.charAt(i) + w2.charAt(i);
        }
        return result;
    }

    public static void main(String[] args) 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int l1 = sc.nextInt();
        String word1 = sc.next();
        int l2 = sc.nextInt();
        String word2 = sc.next();

        String result = merged(word1, word2, l1, l2);
        // Final result is printed
        System.out.println(result);
    }
}