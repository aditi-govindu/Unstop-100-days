/*
Description: Robert wants to organize a marathon across your city.

The city has  landmarks numbered from  to  that can act as starting or finishing points. The landmarks are connected by  roads. Each road has a length of . The city map resembles a binary tree in which each landmark represents a vertex of the tree, and each road represents an edge. The tree is rooted at vertex 1.

As the first step in planning, he wants to find the longest simple path between any two landmarks in the city. Help Robert find the maximum length of the marathon he can organize.          

*/

#include <bits/stdc++.h>
using namespace std;
// structure for tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<pair<int, int>> inp;

// recursive function to construct binary tree from 
// the given input format
void constructTree(int i, TreeNode* node){
    if(inp[i].first > -1){
        node->left = new TreeNode(inp[i].first);
        constructTree(inp[i].first - 1, node->left);
    }
    if(inp[i].second > -1){
        node->right = new TreeNode(inp[i].second);
        constructTree(inp[i].second - 1, node->right);
    }
}

// recursive function to return height of any given node
int height(TreeNode *node, int &diameter){
    // base case for NULL nodes
    if(!node) return 0;

    // find height of left and right subtree
    // recursively
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);

    // diameter can be the sum of left and right 
    // subtree heights
    diameter = max(diameter, leftHeight + rightHeight);

    // return height of the current node
    return (max(leftHeight, rightHeight) + 1);
}

// function to call the recursive height function
// and return the final answer
int findDiameter(TreeNode *root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main(){
    // reading inputs
    int n;
    cin >> n;
    inp.resize(n);
    for(int i = 0; i < n; i++)
        cin >> inp[i].first >> inp[i].second;
    
    // defining root node and constructing binary tree
    TreeNode* root = new TreeNode(1);
    constructTree(0, root);

    // call function to find diameter
    int res = findDiameter(root);

    // print result
    cout << res << endl;
    return 0;
}