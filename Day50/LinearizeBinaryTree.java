import java.io.*;
import java.util.*;

/*
Description: You are given a binary tree where each node may have a left child and/or a right child. You need to convert this binary tree into a linear data structure, i.e. linearize the binary tree, in the following way:

The linearized tree should use the same node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The linearized tree should be in the same order as the preorder traversal of the binary tree.
Since all nodes will have only the right child, hence the resultant tree will be right-skewed.
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
            ob.flatten(root);
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
        if (input.length() == 0) 
        {
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

class Solution
{
    public void flatten(TreeNode root) 
    {
        // Handle the null scenario
        if (root == null) {
            return;
        }

        TreeNode node = root;

        while (node != null) {

            // If the node has a left child
            if (node.left != null) {

                // Find the rightmost node
                TreeNode rightmost = node.left;
                while (rightmost.right != null) {
                    rightmost = rightmost.right;
                }

                // rewire the connections
                rightmost.right = node.right;
                node.right = node.left;
                node.left = null;
            }

            // move on to the right side of the tree
            node = node.right;
        }
    }
}