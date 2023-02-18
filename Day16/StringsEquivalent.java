/*
Description: Given two string arrays word1 and word2, return true ifthe two arrays represent the same string, and false otherwise.A string is represented by an array if the array elements concatenated inorder forms the string. 
*/

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone{
	 public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {
         int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        while(true){
            if(word1[i1].charAt(j1) != word2[i2].charAt(j2)) return false;
            if(j1 == word1[i1].length()-1){i1++; j1 = 0;}
            else j1++;
            if(j2 == word2[i2].length()-1){i2++; j2 = 0;}
            else j2++;
            if(i1 == word1.length && i2 == word2.length)
                return true;
            else if(i1 == word1.length || i2 == word2.length)
                return false;
        }
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt(); //number of words
		String[] arr1 = new String[n]; //array of string ["dog , "cat"];
		for(int i = 0; i < arr1.length; i++){
			arr1[i] = scn.next();
		}
		
		int y = scn.nextInt(); //number of words
		String[] arr2 = new String[y]; //array of string ["dog , "cat"];
		for(int i = 0; i < arr2.length; i++){
			arr2[i] = scn.next();
		}
		
		boolean ans = arrayStringsAreEqual(arr1,arr2);
		System.out.println(ans);

	}
}