/*
Given a Generic tree, find its maximum height.

The depth of a node is defined as the number of nodes it is away from the root including itself (depth of root is 0). 
The height of a tree is defined as the depth of the deepest node.

Or in other terms, the maximum height is the number of nodes along the longest 
path from the root node down to the farthest leaf node.
*/

import java.io.*;
import java.util.*;

class Node {
  public int val;
  public List<Node> children;

  public Node() {
    this(0);
  }

  public Node(int _val) {
    val = _val;
    children = new ArrayList<>();
  }

  public static String serialize(Node root) {
    if (root == null)
      return "[]";
    StringBuilder res = new StringBuilder("[" + root.val + ",null,");
    Queue<Node> q = new ArrayDeque<>();
    q.add(root);

    while (q.size() > 0) {
      int count = q.size();
      while (count-- > 0) {
        Node curr = q.remove();
        for (Node child : curr.children) {
          q.add(child);
          res.append(child.val + ",");
        }
        res.append("null,");
      }
    }
    res.setCharAt(res.length() - 1, ']');
    return res.toString();
  }

  public static Node deserialize(String input) {
    if (input.equals("[]") == true)
      return null;

    input = input.substring(1, input.length() - 1);
    String[] nodes = input.split(",");

    Node root = new Node(Integer.parseInt(nodes[0]));
    Queue<Node> q = new LinkedList<>();
    q.add(root);

    int index = 2;
    while (!q.isEmpty()) {
      Node par = q.remove();
      while (index < nodes.length) {
        String str = nodes[index++];
        if (str.equals("null") == true)
          break;

        Node child = new Node(Integer.parseInt(str));
        par.children.add(child);
        q.add(child);
      }
    }

    return root;
  }
}

class Solution {
  public int maxDepth(Node root) {
    // if the root is null, i.e. subtree is empty, return 0
    if (root == null)
      return 0;
    // if the children's arraylist is empty, then it is leaf node, hence return 1
    if (root.children.isEmpty())
      return 1;
    
    // Find the height of all subtrees.
    List<Integer> heights = new LinkedList<>();
    for (Node item : root.children) {
      heights.add(maxDepth(item));
    }

    // return the maximum height among them + 1
    return Collections.max(heights) + 1;
  }
}

class Main {
  public static void main(String[] args) throws Exception {

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    Solution ob = new Solution();
    while ((line = in.readLine()) != null) {
      Node root = Node.deserialize(line);
      System.out.println(ob.maxDepth(root));
    }
  }
}