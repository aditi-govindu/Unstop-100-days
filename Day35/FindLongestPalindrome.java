/*
Description:  Given a string s, find the longest substring in s. A substring is a contiguous sequence of characters within a string, which is also a palindrome .A palindrome is a word, phrase, or sequence that reads the same backwards as forwards.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scn = new Scanner(System.in);
		String s = scn.nextLine();
	System.out.println(longestPalindrome(s));
		
	}

    public static String longestPalindrome(String s) 
    {
        boolean[][] dp = new boolean[s.length()][s.length()];
        int len = 0; //maximum length of palindromic substring
        int sians = 0; //starting index of answer
        for(int g = 0; g < s.length() ; g++){ //g=gap, for diagnol traversal
            for(int i = 0 , j = g; j < s.length() ; i++,j++){
                if(g==0){
                    dp[i][j] = true;
                }else if(g==1){
                    if(s.charAt(i) == s.charAt(j)){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1]==true ){
                            dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }
                if(dp[i][j]==true){
                    len = g+1 ;
                    sians = i;
                }
            }
        }
        return s.substring(sians,sians+len); 
    }
}