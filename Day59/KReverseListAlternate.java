import java.util.*;
import java.lang.*;
import java.io.*;

/*
Description: You are given a linked list with N nodes. You have to write a program that swaps elements of the list pairwise.

You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/

class ListNode 
{
	int val;
	ListNode next;

	ListNode() 
    {
		val = 0;
	}

	ListNode(int x) 
    {
		val = x;
	}

	public static String listNodeToString(ListNode node) 
    {
		if (node == null) 
        {
			return "[]";
		}

		String result = "";
		while (node != null) 
        {
			result += Integer.toString(node.val) + ", ";
			node = node.next;
		}
		return "[" + result.substring(0, result.length() - 2) + "]";
	}

	public static int[] stringToIntegerArray(String input) 
    {
		input = input.trim();
		input = input.substring(1, input.length() - 1);
		if (input.length() == 0)
			return new int[0];

		String[] parts = input.split(",");
		int[] output = new int[parts.length];
		for (int index = 0; index < parts.length; index++) 
        {
			String part = parts[index].trim();
			output[index] = Integer.parseInt(part);
		}
		return output;
	}

	public static ListNode stringToListNode(String input) 
    {
		// Generate array from the input
		int[] nodeValues = stringToIntegerArray(input);

		// Now convert that list into linked list
		ListNode dummyRoot = new ListNode(0);
		ListNode ptr = dummyRoot;
		for (int item : nodeValues) 
        {
			ptr.next = new ListNode(item);
			ptr = ptr.next;
		}
		return dummyRoot.next;
	}
}

class Solution 
{
	public ListNode swapPairs(ListNode head) 
    {
		// Dummy node acts as the prevNode for the head node
		// of the list and hence stores pointer to the head node.
		ListNode dummy = new ListNode(-1);
		dummy.next = head;

		ListNode prevNode = dummy;

		while ((head != null) && (head.next != null)) 
        {
			// Nodes to be swapped
			ListNode firstNode = head;
			ListNode secondNode = head.next;

			// Swapping
			prevNode.next = secondNode;
			firstNode.next = secondNode.next;
			secondNode.next = firstNode;

			// Reinitializing the head and prevNode for next swap
			prevNode = firstNode;
			head = firstNode.next; // jump
		}

		// Return the new head node.
		return dummy.next;
	}
}

class Main {
	public static void main(String[] args) throws java.lang.Exception 
    {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		Solution ob = new Solution();

		while ((line = in.readLine()) != null) 
        {
			ListNode node = ListNode.stringToListNode(line);
			System.out.println(ListNode.listNodeToString(ob.swapPairs(node)));
		}
	}
}