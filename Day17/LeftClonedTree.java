/*
Description: You are given a Binary Tree. You need to create the Left Clone of the input binary tree.

The function is expected to create a new node for every node equal in value to it and inserted between itself and its left child.
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception 
    {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        Solution ob = new Solution();
        while ((line = in.readLine()) != null) {
            TreeNode root = TreeNode.stringToTreeNode(line);
            ob.leftClone(root);
            System.out.println(TreeNode.treeNodeToString(root));
        }
    }
}

class TreeNode 
{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        val = 0;
    }

    TreeNode(int x) {
        val = x;
    }

    public static TreeNode stringToTreeNode(String input) 
    {
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
    public void leftClone(TreeNode node) {
        if (node == null)
            return;

        leftClone(node.left);
        leftClone(node.right);

        TreeNode copyNode = new TreeNode(node.val);
        copyNode.left = node.left;
        node.left = copyNode;
    }
}