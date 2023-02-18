#include <bits/stdc++.h>
using namespace std;

/*
Description: You will be given root of binary tree your task is to prune all right node of a given tree.

Prune means you have to place null to every root right if it exists.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *create(vector<int> &arr, int level)
{
    if (arr.size() <= 0 || level == 0)
        return nullptr;
    TreeNode *root = new TreeNode(arr[0]);
    vector<int> left, right;
    
    for (int i = 1; i <= arr.size() / 2; i++)
        left.emplace_back(arr[i]);

    for (int i = arr.size() / 2 + 1; i < arr.size(); i++)
        right.emplace_back(arr[i]);

    root->left = create(left, level - 1);
    root->right = create(right, level - 1);
    return root;
}

TreeNode *buildTree(vector<int> &arr, int level)
{
    if (arr.size() == 0 || level == 0)
        return nullptr;
    int cnt = 0;
    queue<TreeNode *> que;
    while (cnt < level)
    {
        for (int i = cnt * 2; i <= cnt * 2 + 1; i++)
        {
        }
    }
    return nullptr;
}

void dfs(TreeNode *root,vector<int> &arr)
{
    if (!root)
        return;

    arr.push_back(root->val);
    dfs(root->left,arr);
    dfs(root->right,arr);
}


// optimized
void pruneTree(TreeNode *root)
{
    if(!root) return;
    root->right = nullptr;
    pruneTree(root->left);
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int numberOfLevel;
        cin >> numberOfLevel;
        int numberOfNodes = pow(2, numberOfLevel) - 1;
        vector<int> arr(numberOfNodes);

        for (int i = 0; i < numberOfNodes; i++)
            cin >> arr[i];
        
        TreeNode *root = create(arr, numberOfLevel);
        pruneTree(root);
        vector<int> a;
        dfs(root,a);
        for(auto it : a) cout<<it<<" ";
        cout<<"\n";
    }
}