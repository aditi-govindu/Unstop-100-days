/*
Description: Rahul has a unit test in school, but he woke up very late in the morning. He has to go to school as soon as possible. Rahul's house is situated at 0,0 index of integer matrix and his school is at n-1, m-1 index of the matrix. You have to help Rahul to find the shortest route.

You are provided with a matrix, in which the ith, jth value represents distance.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution 
{
    public static void main(String[] args) throws Exception 
    {
        Scanner sc  =  new Scanner(System.in);
        int n =  sc.nextInt();
        int m =  sc.nextInt();
        int[][] arr = new int[n][m];
        for(int i = 0; i<n; i++)
        {
            for(int j  = 0; j<m; j++)
                arr[i][j] =  sc.nextInt();
        }
        int[][]  qb  =  new int[n][m];
        System.out.println(routeToSchool(arr,qb));     
    }

    public  static int routeToSchool(int[][] arr, int[][] qb)
    {
       for(int i = arr.length-1; i>=0; i--)
       {
           for(int j = arr[0].length-1; j>=0; j--)
           {
                if(i == arr.length-1 && j == arr[0].length-1)
                    qb[i][j] = arr[i][j];
                else if(i == arr.length-1)
                    qb[i][j] = qb[i][j+1] + arr[i][j];
                else if(j == arr[0].length-1)
                    qb[i][j] = qb[i+1][j] + arr[i][j] ;
                else
                {
                    int r =   qb[i][j+1];
                    int d =      qb[i+1][j] ;
                    int p = Math.min(r,d) + arr[i][j];
                    qb[i][j] = p;   
                }    
           }
       } 
       return qb[0][0];
    } 
}