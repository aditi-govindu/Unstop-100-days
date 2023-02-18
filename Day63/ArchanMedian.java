import java.util.*;
import java.io.*;

/* Description: Archan is a professor at the Academy Of Technology. One day he calls his student Niladri to play an interesting game. He asked Niladri to imagine an empty bucket. He then does k queries. In each query he asks Niladri to do either of the following operations:

Add a number v to the bucket.
Get the median of all numbers added to the bucket.
Niladri needs to answer Archan only in the type 2 query. Can you help Niladri to do so?

Note: Answer within 10-5 of the actual answer will be accepted.
*/

public class Main 
{
    static PriorityQueue<Integer> minH = new PriorityQueue<>();
    static PriorityQueue<Integer> maxH = new PriorityQueue<>((a, b) -> b - a);

    public static  void addNum(int num) 
    {
        // Using heap sort for sorting of numbers
        int maxHsize = maxH.size();
        int minHsize = minH.size();

        if (maxHsize == 0)
            maxH.add(num);
        else if (maxHsize == minHsize) 
        {
            if (num < minH.peek())
                maxH.add(num);
            else 
            {
                int temp = minH.remove();
                maxH.add(temp);
                minH.add(num);
            }
        } 
        else 
        {
            if (minH.size() == 0) 
            {
                if (num > maxH.peek())
                    minH.add(num);
                else 
                {
                    int temp = maxH.remove();
                    minH.add(temp);
                    maxH.add(num);
                }
            } 
            else if (num >= minH.peek())
                minH.add(num);
            else 
            {
                if (num < maxH.peek()) 
                {
                    int temp = maxH.remove();
                    minH.add(temp);
                    maxH.add(num);
                } 
                else
                    minH.add(num);
            }
        }
    }

    public static double findMedian() 
    {
        // Median is middle of the list
        if (maxH.size() == minH.size())
            return (double) ((double) maxH.peek() + minH.peek()) / 2;
        else
            return maxH.peek();
    }


    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        int k = scn.nextInt();

        while(k-->0)
        {
            String s = scn.next();
            if(s.equals("add"))
            {
                int num = scn.nextInt();
                addNum(num);
            }
            else
            {
                double ans = findMedian();
                System.out.println(ans);
            }
        }
    }
}