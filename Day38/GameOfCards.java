import java.util.*;
import java.io.*;

/*
Description: Kritika and Jaydip were playing a game of cards. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i]. Initially they can order the deck in any ways they want and all the cards start face down (unrevealed) in one deck.

Now they perform certain operations:

Kritika take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then Jaydip put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, then they start from step 1 else they stop.
Return an ordering of the deck that would reveal the cards in increasing order to Kritika.
*/

public class deck 
{
    //reversing our array 
    public static void reverse(int[] array) 
    {
        int n = array.length;
        //traversing the array from 0 to n/2
        for (int i = 0; i < n / 2; i++) 
        {
            //swapping the elements for the reversal of array
            int temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
        }
    }

    public static int[] deckRevealedIncreasing(int[] deck) 
    {
         int n = deck.length;
        //sorting the array using java in-built sorting function
        Arrays.sort(deck);
        //calling reverse function
        reverse(deck);
        //creating our queue using linkedlist
        LinkedList<Integer> que = new LinkedList<>();

        //traversing our array deck
        for (int i = 0; i < deck.length; i++) 
        {
            if (que.size() > 0) 
            {
                // adding the last element of the queue to the front
                que.addFirst(que.removeLast());
            }
            //adding the deck[i] to the front
            que.addFirst(deck[i]);
        }

        int ans[] = new int[n];
        int i = 0;
        //removing the elements from the queue until the size of queue is 0 and i < n
        while (que.size() > 0 && i < n) 
        {
            //adding the removed element into our answer array
            ans[i++] = que.removeFirst();
        }
        return ans;
    }

    public static void main(String[] args) throws Exception 
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) 
        {
            arr[i] = scn.nextInt();
        }

        //calling our function deckRevealedIncreasing which returns our answer array
        int ans[] =  deckRevealedIncreasing(arr);
        for(int i=0;i<n;i++)
        {
            //printing our final answer
            System.out.print(ans[i]+" ");
        }
    }
}