import java.util.*;
import java.io.*;

/* Descriprtion: Kritika is given an m x n binary matrix grid.
A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
Get the highest possible score after making any number of moves (including zero moves) let this value be m,  print the count of the number of primes less than or equal to m.
*/

public class Main
{
    public static int matrixScore(int[][] grid) {
        int N = grid.length;
        int M = grid[0].length;
        int ans = N; //we know each row must begin with 1
        for (int i = 1; i < M; i++){
            int count = 0;
            for (int j = 0; j < N; j++)
                if (grid[j][i] == 1 - grid[j][0])
                    count++;
            ans <<= 1; //shift it
            ans += Math.max(count, N - count);
        }

        return ans;
    }

 public static int sieveOfEratosthenes(int n) {
 
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) {
 
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int count=0;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true)
                count++;
        }
        return count;
    }


    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int row = scn.nextInt();
        int col = scn.nextInt();
        int arr[][] = new int[row][col];

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j] = scn.nextInt();
            }
        }
       int res =  matrixScore(arr);
       System.out.println(sieveOfEratosthenes(res));


    }
}