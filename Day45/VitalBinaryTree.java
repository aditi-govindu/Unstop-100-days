import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Description: Given an integer array with no duplicates. A vital binary tree building on this array is defined as follows:
   a)The root is the maximum number in the array.
   b)The left subtree is the maximum tree constructed from the left part subarray divided by the maximum number.
   c)The right subtree is the maximum tree constructed from the right part subarray divided by the maximum number.

You need to construct the required binary tree and print the level order serialization of this binary tree. (Where null children are denoted by null itself).
*/

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Solution ob = new Solution();
        int n = scn.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = scn.nextInt();
        System.out.println(TreeNode.treeNodeToString(ob.constructMaximumBinaryTree(nums)));

    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        val = 0;
    }

    TreeNode(int x) {
        val = x;
    }

    public static TreeNode stringToTreeNode(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return null;
        }

        String[] parts = input.split(",");
        String item = parts[0];
        TreeNode root = new TreeNode(Integer.parseInt(item));
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);

        int index = 1;
        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();

            if (index == parts.length) {
                break;
            }

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int leftNumber = Integer.parseInt(item);
                node.left = new TreeNode(leftNumber);
                nodeQueue.add(node.left);
            }

            if (index == parts.length) {
                break;
            }

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int rightNumber = Integer.parseInt(item);
                node.right = new TreeNode(rightNumber);
                nodeQueue.add(node.right);
            }
        }
        return root;
    }

    public static String treeNodeToString(TreeNode root) {
        if (root == null) {
            return "[]";
        }

        String output = "";
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);
        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();

            if (node == null) {
                output += "null, ";
                continue;
            }

            output += String.valueOf(node.val) + ", ";
            nodeQueue.add(node.left);
            nodeQueue.add(node.right);
        }
        return "[" + output.substring(0, output.length() - 2) + "]";
    }
}

class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        LinkedList<TreeNode> lklist = new LinkedList<>();
        TreeNode left = null;
        for (int num : nums) {
            TreeNode cur = new TreeNode(num);
            while (!lklist.isEmpty() && (lklist.peekFirst()).val < cur.val) {
                cur.left = lklist.pop();
            }

            if (!lklist.isEmpty()) {
                lklist.peekFirst().right = cur;
            }
            lklist.push(cur);
        }

        return lklist.peekLast();
    }
}