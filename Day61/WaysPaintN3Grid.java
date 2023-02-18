import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Description: Marco likes painting a lot. He wants to paint a grid having N*3 dimensions. He only has three colors with him: “Red”, “Yellow”, “Green”. He is curious to know in how many ways he can paint the grid such that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides).

Help Marco to find his answer.

Note : Since answer can be large it must be computed modulo 10^9 + 7
*/

class Solution 
{
    public static int numOfWays(int n) 
    {
        // Base case for n = 1: Unique combinations are 6, Non unique are 6
        long distinct = 6;
        long nonDistinct = 6;
        long mod = 1000000007;

        for(int i = 1 ; i < n ; i++)
        {
            long newDistinct = (distinct * 2 + nonDistinct * 2) % mod;
            long newNonDistinct = (distinct * 2 + nonDistinct * 3) % mod;

            distinct = newDistinct;
            nonDistinct = newNonDistinct;
        }

        return (int)((distinct + nonDistinct) % mod);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int answer = numOfWays(n);
        System.out.println(answer);
    }
}