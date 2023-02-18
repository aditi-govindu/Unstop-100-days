import java.io.*;
import java.util.*;

/*
Description: Shyam is fond of Binary Search Trees. He has been provided a BST and an integer key. His task is to find the node with a value equal to that key. If found, he will delete the node from Binary Search Tree so that no property is violated. 

A BST is defined as follows:
    a) The left subtree of a node contains only nodes with keys less than the node's key.
    b) The right subtree of a node contains only nodes with keys greater than the node's key.
    c) Both the left and right subtrees must also be binary search trees.
*/

public class Main {
    public static void main(String[] args) throws Exception
    {
        Scanner scn = new Scanner(System.in);
        Solution ob = new Solution();
        String str = scn.next();
        int key = scn.nextInt();
        TreeNode root = TreeNode.stringToTreeNode(str);
        System.out.println(TreeNode.treeNodeToString(ob.deleteNode(root, key)));
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
    public TreeNode deleteNode(TreeNode node, int key) {
        if (node == null)
            return node;
        if (node.val < key)
            node.right = deleteNode(node.right, key);
        else if (node.val > key)
            node.left = deleteNode(node.left, key);
        else {

            if (node.left == null && node.right == null)
                return null;
            if (node.right == null || node.left == null)
                return node.left != null ? node.left : node.right;

            TreeNode temp = findDeleteReplaceRight(node);
            node.val = temp.val;
            node.right = deleteNode(node.right, temp.val);
        }
        return node;

    }

    public static TreeNode findDeleteReplaceRight(TreeNode root) {
        TreeNode right = root.right;
        while (right.left != null)
            right = right.left;
        return right;
    }
}