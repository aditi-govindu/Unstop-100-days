/*
Description: There are infinity number of roads and every road are parallel to each other. 
Roadside of every road there are some houses. 
The number of houses for ith road should be 2i. 
Every houses have sequence number starting from 1. 
The arrangement of house is like complete binary tree. 
But if the value of i is even then distribution sequence number is from form left to right 
and if i is odd then distribution is from right to left.
You will be provided with sequence number of your house and you have to reach house 
having sequence number 1. Return arraylist containing every house sequence number which 
you must have to visit inorder to reach 1.
*/

import java.util.*;

class Main 
{
   static List<Integer> result;
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(getPath(n));
    }
    
    public static List<Integer> getPath(int label) 
    {
        List<Integer> result = new ArrayList<>();
        int parent = label;
        result.add(parent);

        while(parent != 1) 
        {
            // Find depth of tree as parent/2
            int depth = (int)(Math.log(parent)/Math.log(2));
            int offset = (int)Math.pow(2, depth + 1) - 1 - parent;
            // Parent is child / 2
            parent = ((int)Math.pow(2, depth) + offset) / 2;
            result.add(parent);   
        }
        // If i is even, reverse traversal
        Collections.reverse(result);
        return result;
    }
}