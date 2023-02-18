/*
Description: Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of 
the intervals non-overlapping.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static int eraseOverlapIntervals(int[][] intervals) 
    {
        if (intervals.length == 0)
        return 0;

        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        int ans = 0;
        int currentEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; ++i)
            if (intervals[i][0] >= currentEnd)
                currentEnd = intervals[i][1];
            else
                ++ans;

        return ans;
    }

    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner scn = new Scanner(System.in);
        int row = scn.nextInt();
        int col = scn.nextInt();
        int array[][] = new int[row][col];

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                array[i][j] = scn.nextInt();
        }
        int ans=eraseOverlapIntervals(array); 
        System.out.println(ans);
    }
}