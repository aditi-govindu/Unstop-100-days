import java.util.*;

/*
Description: You are given an array A of N Strings.
You have to group all the strings in A such that all the strings in a group are "special-equivalent". You have to return the number of such groups.
Two strings are special-equivalent if after any number of moves, S == T.
A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j]
*/

 public class Main 
 {
     public static int numSpecialEquivGroups(String[] A) 
     {
         Set<String> set = new HashSet<>();
 
         for (String s : A) 
         {
             // Segregate even and odd characters
             int[] odd = new int[26];
             int[] even = new int[26];
             for (int i = 0; i < s.length(); i++) 
             {
                 if (i % 2 == 1)
                     odd[s.charAt(i) - 'a']++;
                 else
                     even[s.charAt(i) - 'a']++;
             }
             String sig = Arrays.toString(odd) + Arrays.toString(even);
             set.add(sig);
         }
 
         return set.size();
     }
 
     public static void main(String[] args) 
     {
         Scanner sc = new Scanner(System.in);
         int N = sc.nextInt();
         String[] arr = new String[N];
 
         for (int i = 0; i < arr.length; i++) 
            arr[i] = sc.next();
 
         System.out.println(numSpecialEquivGroups(arr));
     }
 
     public static void display(String[] arr) 
     {
         // Display results to user
         for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
 
        System.out.println();
     }
 }