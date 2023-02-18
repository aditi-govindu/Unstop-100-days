import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
Description: You are given the root of a binary tree where every node's value is either a 0 or a 1.

You need to delete some of the nodes of the binary tree such that there exists no subtree which does not have a node with value 1 in it.
*/

public class Main 
{
    public static void main(String[] args) throws Exception 
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        Solution ob = new Solution();
        while ((line = in.readLine()) != null) 
        {
            TreeNode root = TreeNode.stringToTreeNode(line);
            System.out.println(TreeNode.treeNodeToString(ob.pruneTree(root)));
        }
    }
}

class TreeNode 
{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() 
    {
        val = 0;
    }

    TreeNode(int x) 
    {
        val = x;
    }

    public static TreeNode stringToTreeNode(String input) 
    {
        // Convert user input to array
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0)
            return null;

        String[] parts = input.split(",");
        String item = parts[0];
        TreeNode root = new TreeNode(Integer.parseInt(item));
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);

        int index = 1;
        while (!nodeQueue.isEmpty()) 
        {
            // Insert nodes in tree, level wise
            TreeNode node = nodeQueue.remove();

            if (index == parts.length)
                break;

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) 
            {
                int leftNumber = Integer.parseInt(item);
                node.left = new TreeNode(leftNumber);
                nodeQueue.add(node.left);
            }

            if (index == parts.length)
                break;

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) 
            {
                int rightNumber = Integer.parseInt(item);
                node.right = new TreeNode(rightNumber);
                nodeQueue.add(node.right);
            }
        }
        return root;
    }

    public static String treeNodeToString(TreeNode root) 
    {
        // Convert tree to string to show the user
        if (root == null)
            return "[]";

        String output = "";
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);
        while (!nodeQueue.isEmpty()) 
        {
            TreeNode node = nodeQueue.remove();

            if (node == null) 
            {
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

class Solution 
{
    public TreeNode pruneTree(TreeNode root) 
    {
        if (root == null)
            return null;
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);

        // If root is 0 and left, right children are null, remove subtree
        if (root.val == 0 && root.left == null && root.right == null)
            return null;
        return root;
    }
}