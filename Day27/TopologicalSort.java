/*
Description: You are given a directed acyclic graph. The vertices represent tasks and edges represent dependencies between tasks.

You are required to find and print the order in which tasks could be done.

The task that should be done at last should be printed first and the task which should be done first should be printed last.

This is called the topological sort, which is a permutation of vertices for a directed acyclic graph is called topological sort if, for all directed edges u-v, u appears before v in the graph
*/

import java.io.*;
import java.util.*;

public class Main {
  static class Edge {
    int src;
    int nbr;

    Edge(int src, int nbr) {
      this.src = src;
      this.nbr = nbr;
    }
  }

  @SuppressWarnings("unchecked")
  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);

    int vtces = scn.nextInt();
    ArrayList<Edge>[] graph = new ArrayList[vtces];
    for (int i = 0; i < vtces; i++) {
      graph[i] = new ArrayList<>();
    }

    int edges = scn.nextInt();
    for (int i = 0; i < edges; i++) {
      int v1 = scn.nextInt();
      int v2 = scn.nextInt();
      graph[v1].add(new Edge(v1, v2));
    }

    boolean[] visited = new boolean[vtces];
    Stack<Integer> st = new Stack<>();
    for (int v = 0; v < vtces; v++) {
      if (visited[v] == false) {
        topological(graph, v, visited, st);
      }
    }

    while (st.size() > 0) {
      System.out.println(st.pop());
    }
  }

  public static void topological(ArrayList<Edge>[] graph, int src, boolean[] visited, Stack<Integer> st) {
    visited[src] = true;
    for (Edge e : graph[src]) {
      if (!visited[e.nbr]) {
        topological(graph, e.nbr, visited, st);
      }
    }
    st.push(src);
  }
}