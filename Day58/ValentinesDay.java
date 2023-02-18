import java.util.*;
import java.io.*;

// Rohit and Shalini want to go to a date on Valentine Day. 
// Shalini wants to spend a total amount sum for a meal which he told Rohit a day before.
// Rohit only has coins of n types(a0,a1,...,an-1).
// Each type of coin has infinite supply and denotes its value
// Now he wants to fulfill Shalini wish by paying exactly the sum amount, else Shalini may get annoyed 
// and have a break-up.
// You need to tell the minimum no. of coins that Rohit needs to carry to pay the sum amount.
// If he cant pay the exact sum amount print -1.

public class Main 
{
    public static int coinChange(int[] coins, int amount) 
    {
        // Dynamic array approach for coins
        int dp[] = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;

        for (int i = 0; i <= amount; i++) 
        {
            for (int j = 0; j < coins.length; j++) 
            {
                if (i >= coins[j])
                    dp[i] = Math.min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        // If amount reached, return it. Else return -1
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }


    public static void main(String[] args) 
    {
        Scanner scn = new Scanner(System.in);
        int n=scn.nextInt();
        int coins[] = new int[n];

        for(int i=0;i<n;i++)
            coins[i]=scn.nextInt();

        // Display results to user
        int amount = scn.nextInt();
        System.out.println(coinChange(coins, amount));
    }
}