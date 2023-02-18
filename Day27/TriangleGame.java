import java.util.*;

/*
Description: You are given a triangle shape figure as shown in the figure. You have to decode the pattern in each row and find all the numbers in the nth row. (indexing starts from 0)
*/

public class Main 
{
  public static ArrayList<Integer> pascalRow(int r) 
  {
    ArrayList<Integer> list = new ArrayList<>();
    long val = 1;
    for (int c = 0; c <= r; c++) 
    {
      list.add((int)val);
      val = val * (r - c) / (c + 1);
    }

    return list;
  }

  public static void main(String[] args) 
  {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();

    ArrayList<Integer> res = pascalRow(n);
    for (int val : res) {
      System.out.print(val + " ");
    }
    System.out.println();
  }
}