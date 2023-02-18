#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

/*
 Ashish was learning about the Binary Search Trees, which are special types of trees that satisfy these constraints

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
His friend, Sarthak, saw him and thought of challenging him. He defined a transition as replacing each node of the tree with the original node plus the sum of all tree nodes greater than the original node in the tree.

Given a Binary Search Tree, print the sum of all nodes after the transition of the Binary Search Tree. Since the answer can be too large, output it modulo (109 + 7).
*/

struct TreeNode
{   
    //structure of tree node
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBST() //function for inputting the BST
{
    int rootd;
    cin>>rootd;

    if(rootd == -1)
        return NULL;

    TreeNode* root = new TreeNode(rootd);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();
        int leftd;
        cin>>leftd;
        if(leftd != -1)
        {
            TreeNode* node = new TreeNode(leftd);
            front->left = node;
            q.push(node);
        }

        int rightd;
        cin>>rightd;
        if(rightd != -1)
        {
            TreeNode* node = new TreeNode(rightd);
                front->right = node;
            q.push(node);
        }
    }
    return root;
}

void helpBST(TreeNode* root, int &curr, int &ans) //for doing the transition
{
    if(root == NULL)
        return;
    helpBST(root->right, curr,ans); //reverse inorder traversal
    curr = (curr + root->val)%mod;
    ans = (ans + curr)%mod;
    helpBST(root->left, curr, ans);
}

int main()
{
    TreeNode* root = createBST();
    int ans = 0;
    int curr = 0;
    helpBST(root, curr, ans);
    cout<<ans<<endl;
    return 0;
}