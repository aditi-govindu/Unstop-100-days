/*
Description: Ankit is given an array target and an integer n.

In each iteration, he is asked to read a number from list = [1, 2, 3, ..., n].

He needs to build the target array using the following operations:

"Push": Reads a new element from the beginning list, and pushes it in the array.
"Pop": Deletes the last element of the array.
If the target array is already built, stop reading more elements.
He is required to find a list of the operations needed to build the target. It is also guaranteed that such a list will always exist.  But he is confused. Can you help him?
*/

import java.util.*;
import java.io.*;

public class Main
{
     public static List<String> buildArray(int[] target, int n) 
     {   
        List<String> ans = new ArrayList<>();
        
        int input = 1;
        for(int i: target)
        {
            // If number not in pattern, add and remove from list
            while(input < i)
            {
                ans.add("Push");
                ans.add("Pop");
                input++;
            }
            // Number in pattern. Add to list
            ans.add("Push");
            input++;
            
        }
        return ans;
    }

    public static void main(String[] args) 
    {
        Scanner scn = new Scanner(System.in);
        int m = scn.nextInt();
        int target[] = new int[m];
        for (int i = 0; i < m; i++) {
            target[i] = scn.nextInt();
        }
        int n = scn.nextInt();
        List<String> ans = buildArray(target, n);
        for (String str : ans) {
            System.out.print(str + " ");
        }
    }
}