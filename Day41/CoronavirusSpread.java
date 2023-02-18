import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Description: There is a town in the form of a 2-D Matrix. In each grid of the matrix, there will be one person or no person. But some person is infected with the coronavirus, and they will infect another person who is adjacent to them in 1 minutes of time. Now your task is to find the minimum time required so that all the person become infected. If it is impossible to infect every person then simply return -1.

Note: each cell can have one of three values: 

0 represents an empty cell,
1 representing a non-infected person, or
2 representing an infected person.
*/

class Solution 
{
    public static int orangesRotting(int[][] grid) 
    {
        // Return 0 for no oranges
        if(grid.length == 0 || grid[0].length == 0 || grid == null)
            return 0;
        int rows = grid.length;
        int columns = grid[0].length;
        
        Queue<int[]>q = new LinkedList<>();
        int fresh = 0;
        
        for(int i =0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                // Add index of rotten orange(2) to queue
                if(grid[i][j] == 2)
                    q.offer(new int[]{i,j});
                // Increment count of fresh orange(1)
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;
        // Check if cell is empty or orange being impacted is negative
        int[][] dir = new int[][]{{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.isEmpty() && fresh > 0)
        {
            int len = q.size();
            for(int i = 0;  i < len; i++)
            {
                // DeQueue first rotten orange
                int[] orange = q.poll();
                for(int[] d : dir)
                {
                    // If orange can be rotten, set it to 2
                    int x = orange[0] + d[0];
                    int y = orange[1] + d[1];
                    if(x < 0 || y < 0 || x >= rows || y >= columns || grid[x][y] == 0 || grid[x][y] == 2)
                        continue;
                    grid[x][y] = 2;
                    // Add orange to rotten queue
                    q.offer(new int[]{x,y});
                    // Decrement fresh count
                    fresh--;
                }
            }
            minutes++;
        }
    if(fresh == 0)
        return minutes;
    return -1;
    }

    public static void main(String[] args) 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int [][] grid = new int [rows][cols];

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                grid[i][j] = sc.nextInt();
        }
        System.out.println(orangesRotting(grid));

    }
}