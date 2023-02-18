import java.io.*;
import java.util.*;

/*
Description: You are provided a Generic Tree or N-ary Tree Data Structure.

You need to perform the following operation on the tree:

Visit every node in "level order fashion" and print them from left to right (level by level).
All nodes on the same level should be separated by a space.
Different levels should be on separate lines. 
*/

class Node 
{
    public int val;
    public List<Node> children;

    public Node() 
    {
        this(0);
    }

    public Node(int _val) 
    {
        val = _val;
        children = new ArrayList<>();
    }

    public static String serialize(Node root) 
    {
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

    public static Node deserialize(String input)
    {
        if (input.equals("[]") == true)
            return null;

        input = input.substring(1, input.length() - 1);
        String[] nodes = input.split(",");

        Node root = new Node(Integer.parseInt(nodes[0]));
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        int index = 2;
        while (!q.isEmpty()) 
        {
            Node par = q.remove();
            while (index < nodes.length) 
            {
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

class Solution 
{
    public List<List<Integer>> levelOrder(Node node) 
    {
        List<List<Integer>> res = new ArrayList<>();
        if(node == null) return res;
        
        Queue < Node > mq = new ArrayDeque < > ( );
        mq.add(node);
        List<Integer> curr = new ArrayList<>();
        while (mq.size() > 0) {
          int cicl = mq.size();
          for (int i = 0; i < cicl; i++) 
          {
            node = mq.remove();
            curr.add(node.val);
      
            for (Node child : node.children) 
              mq.add(child);
          }
          if(curr.size() > 0) res.add(curr);
          curr = new ArrayList<>();
        }
        return res;
      }
}

class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        Solution ob = new Solution();
        while ((line = in.readLine()) != null) 
        {
            Node root = Node.deserialize(line);
            System.out.println(ob.levelOrder(root));
        }
    }
}