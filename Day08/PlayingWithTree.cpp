#include <cmath>
/*
Description: In computer class, every student is somehow relative to each other. The teacher represents all students in the form of a binary search tree (BST).Every student has a  roll number as a random integer. In this binary search tree, the roll number of every student is a node of the binary search tree. He randomly picks up any two students from the class and names them as x and y, respectively. He asks students to find the lowest common ancestor (LCA) of x and y  in the BST.

The lowest common ancestor is defined between two nodes x and y as the lowest node in BST that has both x and y as descendants (where we allow a node to be a descendant of itself).”

Help students to find the lowest common ancestor (LCA) of two nodes, x and y.
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int val)
{
    // Allocate memory and pointers of node
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp -> val = val;
    temp -> left = nullptr;
    temp -> right = nullptr;
    return temp;
}

TreeNode* createTree(vector<int> values, int i, int n)
{
    // Create binary tree where left child is at 2i + 1 and right child at 2i + 2 index of array
    TreeNode *root = nullptr;
    if(i < n)
    {
        root = createNode(values[i]);
        root -> left = createTree(values, 2*i +1, n);
        root -> right = createTree(values, 2*i + 2, n);
    }
    return root;
} 

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(root == nullptr)
        return nullptr;

    // If p on left of root and q on right of root, check left side of tree
    if(p -> val < root -> val && q -> val < root -> val)
        return lowestCommonAncestor(root -> left, p, q);
    // If p on right of root and q on left of root, check right side of tree
    else if(p -> val > root -> val && q -> val > root -> val)
        return lowestCommonAncestor(root -> right, p, q);
    else
        return root;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p, q;
    cin >> n;
    vector<int> arr;

    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
 
    cin >> p;
    cin >> q;
    TreeNode* r = createTree(arr, 0, n);

    TreeNode* pNode = createNode(p);
    TreeNode* qNode = createNode(q);

    TreeNode* ans = lowestCommonAncestor(r, pNode, qNode);
    cout << ans -> val << endl;

    return 0;
}