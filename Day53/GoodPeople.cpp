#include <bits/stdc++.h>
using namespace std;

/*
Description: Mocha has recently gone to a meet. In the meet, there are n people standing in a straight line. Each person is assigned a goodness index. Mocha’s task is to first sort the people in ascending order. After doing that he has to arrange those people in the form of a tree. In the tree, he has to find the number of good people. A person X in a tree is defined as a good person if in the path from the root to X there are no nodes with a value greater than X. Mocha’s task is to return the number of good people.
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// Function to insert nodes in level order
TreeNode* insertLevelOrder(vector<int>& arr, TreeNode* root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);


        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// counting the number of nodes in the tree
int goodNodes(TreeNode* root) 
{
    
    // if root is nullptr return 0
    if(!root)
    	return 0;

    // left count
    int left = goodNodes(root->left);

    // right count
    int right = goodNodes(root->right);
    
    // total count
    return left + right + 1;
}


int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // Sort array before insertion into tree (All smaller below it in tree)
    sort(arr.begin(),arr.end());

    TreeNode* root = insertLevelOrder(arr, root, 0, n);

    int totCount=goodNodes(root);

    cout<<totCount<<endl;

    return 0;
}