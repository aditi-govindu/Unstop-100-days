/*
Description: Rahul is given an integer array arr which contains all unique values; he needs to create a height-balanced tree such that the tree nodes left to the parent node are less in value than the parent node, and the nodes which are right to the parent node always have a greater value than the parent node. Could you help him to create the required tree?

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

import java.io.*;
import java.util.*;

public class Main {
    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public static Node construct(int[] arr,int lo, int hi) {
        if(lo>hi)return null;
        int mid = hi-((hi-lo)/2);
        int data = arr[mid];
        Node left = construct(arr,lo,mid-1);
        Node right = construct(arr,mid+1,hi);
        Node node = new Node(data, left, right);
        return node;
    }
    public static void display(Node node) {
        if (node == null) {
            return;
        }

        String str = "";
        str += node.left == null ? "." : node.left.data + "";
        str += " <- " + node.data + " -> ";
        str += node.right == null ? "." : node.right.data + "";
        System.out.println(str);

        display(node.left);
        display(node.right);
    }


    public static void main(String[] args) throws Exception {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=scn.nextInt();
        }
        Arrays.sort(arr);
        Node root = construct(arr,0,arr.length-1);
        display(root);
    }

}