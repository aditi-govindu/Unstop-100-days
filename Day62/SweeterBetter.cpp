#include <bits/stdc++.h>
using namespace std;

/*
Description: A park in the city has n trees numbered from 1 to n connected by n-1 pavements. This structure resembles a binary tree rooted at tree '1' where trees represent the vertices and pavements represent its edges.

Each tree has a fruit on it. Some of the fruits are sweet, while others are bitter. The ith tree (1 <= i <= n) has a fruit of sweetness ai. if the fruit is bitter, the value of ai will be negative.

You went to the park to collect fruits. You cannot visit any tree more than once, and will have to collect the fruit from each tree you visit from the starting position of your choice. You can decide to return home with all the fruits you collected at any point. Find the maximum value of sweetness that you can collect.
*/

// structure for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<pair<int, int>> inp;
vector<int> wt;
// recursive function to construct a binary tree
// from the given input format
void constructTree(int i, TreeNode* node){
    if(inp[i].first > -1){
        node->left = new TreeNode(wt[inp[i].first]);
        constructTree(inp[i].first, node->left);
    }
    if(inp[i].second > -1){
        node->right = new TreeNode(wt[inp[i].second]);
        constructTree(inp[i].second, node->right);
    }
}

// declaring the result value globally
int res;

// Recursive function MaxPath that returns the
// maximum number of sweetness that can be 
// collected from a path including the given node
// and one/zero of its subtrees
int MaxPath(TreeNode* node){
    // base case
    // if the node is NULL, return 0
    if(!node) return 0;

    // compute the MaxPath for left and right
    // subtree recursively, they cannot be negative
    // because we can chose to not select any node
    // instead of a negative path
    int left_path = max(MaxPath(node->left), (int)0);
    int right_path = max(MaxPath(node->right), (int)0);

    // compute result by taking max value of path including
    // the given node and BOTH of its subtrees
    res = max(res, left_path + right_path + node->val);

    // return max value of path including the given node
    // one ONE/ZERO of its subtrees
    return node->val + max(left_path, right_path);
}

int main(){
    // taking inputs and constructing binary tree
    int n;
    cin >> n;
    wt.resize(n);
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    inp.resize(n);
    for(int i = 0; i < n; i++){
        cin >> inp[i].first >> inp[i].second;
        inp[i].first--;
        inp[i].second--;
    }
    // define root node 1
    TreeNode* root = new TreeNode(wt[0]);
    // recursive function to construct binary tree
    constructTree(0, root);
    // let the result be equal to 0 initially
    // 0 is the minimum value of result because
    // we can chose to select none of the nodes
    res = 0;
    // call to recursive function
    // this returns MaxPath including zero and one of
    // its subtrees, but we do not need that value
    // our answer will be computed during the 
    // recursion process
    MaxPath(root);
    // print the computed result
    cout << res << endl;
    return 0;
}