/*
Description: You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main{
	 public static int markCharactersOf(String word) { //function 
        int result = 0; //result variable
           for (char ch : word.toCharArray()) { //for loop
            int position = ch - 'a';  //position
            result |= 1 << position;
        }
        
        return result;
    }
    
    public static int countConsistentStrings(String allowed, String[] words) { //function
        int allowedChars = markCharactersOf(allowed); //allowedChars
        int answer = 0; //answer variable
        
        for (String word : words) { //for loop
            int wordInWords = markCharactersOf(word);
            
            if ((wordInWords & allowedChars) == wordInWords)
                answer++;
        }
        
        return answer;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scn = new Scanner(System.in);
		String str = scn.nextLine();
		int n = scn.nextInt();
		String[] arr = new String[n];
		for(int i = 0; i < arr.length; i++){
			arr[i] = scn.next();
		}
		int ans = countConsistentStrings(str , arr);
		System.out.println(ans);
	}
}