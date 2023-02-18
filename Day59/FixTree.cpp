#include <bits/stdc++.h>
using namespace std;

/* Description: Raj has a binary tree with n nodes numbered from 1 to n, which is rooted at 1. He wants to represent it on a chart paper using circular stickers as its nodes.He drew the binary tree’s structure and bought n stickersto paste on it later, but while he was busy doing his homework, his little brother pasted them on the chart paper. Raj noticed that his brother had pasted more than one sticker on some of the nodes, and the rest were left empty.

Raj wants to fix this tree, but he can onlymake one of the following moves at once:

Move a sticker from its current node to its parent node (if any).
Move a sticker from its current node to one of its child nodes (if any).
Every time he moves a sticker, the glue on it becomes weaker. So, he wants to minimize the number of moves to make his chart more durable.

Help Raj find the minimum number of moves he needs to make such that each node has exactly one sticker representing it.
*/

// class representing a node of the binary tree
class TreeNode
{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr){}
        TreeNode(int Val): val(Val), left(nullptr), right(nullptr){}
};

vector<pair<int, int>> inp;
vector<int> wt;

// recursive function to construct a binary tree
// from the given input format
void constructTree(int i, TreeNode* node)
{
    if(inp[i].first > -1)
    {
        node->left = new TreeNode(wt[inp[i].first]);
        constructTree(inp[i].first, node->left);
    }
    if(inp[i].second > -1)
    {
        node->right = new TreeNode(wt[inp[i].second]);
        constructTree(inp[i].second, node->right);
    }
}
int ans;

// dfs(node) represents the excess number of stickers
// in the subtree of the given node
int dfs(TreeNode* node)
{
    if(node == NULL)
        return 0;
    int left = dfs(node->left);
    int right = dfs(node->right);
    // add the number of moves we need to make
    // between this node and its children
    // to the answer
    ans += abs(left) + abs(right);

    // return the excess number of stickers
    return node->val + left + right - 1;
}

int main()
{
    // read inputs
    int n;
    cin >> n;
    wt.resize(n);
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    
    inp.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> inp[i].first >> inp[i].second;
        inp[i].first--;
        inp[i].second--;
    }

    // define root node 1
    TreeNode* root = new TreeNode(wt[0]);
    // recursive function to construct binary tree
    constructTree(0, root);
    
    // set the answer to be 0 initially
    ans = 0;

    // call the dfs and compute the answer
    dfs(root);

    // print the final answer obtained after dfs
    cout << ans << endl;
    return 0;
}