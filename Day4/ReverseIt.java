import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Description: We are given a string s consisting of only lowercase letters of english, and a character c. Let the index of last occurence of c be idx, reverse the suffix from idx.
*/

class Solution 
{
    // Reverse the string
    public String reverse(String data, int start, int end)
    {
        String rev = "";
        for(int i = end; i >= start; i--)
            rev += data.charAt(i);
        return rev;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Solution s = new Solution();

        String data = sc.next();
        char letter = sc.next().charAt(0);
        int n = data.length() - 1;

        String ulta = s.reverse(data, 0, n);

        // Location of letter from reverse
        int place = ulta.indexOf(letter);
        String rev = ulta.substring(0, place+1);
        String straight = data.substring(0, n - place);
        // Join and display substrings of straight till c + reversed from index of c
        System.out.println(straight + rev);
    }
}