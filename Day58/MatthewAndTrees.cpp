#include<bits/stdc++.h> 
using namespace std; 

/*
Description: In a computer science class, Mathew’s computer science teacher gave him an array of size ‘n’ and told him to build a tree model with the element of an array. Now Mathew is working on the task of building a tree with the given integers. Mathew builds the tree, and he wants to print the integers of each level of binary tree from left to right and form a new 2d array. Now, Mathew wants your helps to find the new array.
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create(vector < int > arr) 
{ 
    TreeNode* root; 
    if(arr.size() == 0) 
        return NULL; 
    queue<TreeNode*> q; 

    int i = 0;
    // If input is -1, set it to NULL
    TreeNode* t = arr[i] == -1 ? NULL : new TreeNode(arr[i]);
    root = t;
    q.push(root);
    i++;

    while (!q.empty() && i < arr.size()) 
    {
        TreeNode* t1 = q.front();
        q.pop(); 
        if (t1 != NULL) 
        {
            t1->left = arr[i] == -1 ? NULL : new TreeNode(arr[i]);
            q.push(t1->left);
            i++;
            if (i >= arr.size()) 
                break;
            t1->right = arr[i] == -1 ? NULL : new TreeNode(arr[i]);
            q.push(t1->right);
            i++;
        }
    }
    return root;
}

vector < vector< int > > fun(TreeNode *root)
{ 
    if(root==NULL)
        return {};

    vector<vector<int>> ans; 
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *temp;
    int len;

    // Depth first display
    while(!q.empty())
    {
        len=q.size();
        vector<int> v;
        for(int i=0;i<len;i++)
        {
            temp=q.front();
            q.pop();
            v.push_back(temp->val);

            if(temp->left) 
                q.push(temp->left);
            if(temp->right) 
                q.push(temp->right);
        }
        ans.push_back(v);
    }
    return ans;
}

int main() 
{
    int n ; 
    cin >> n;
    vector < int > v(n); 

    for(int i = 0; i<n; i++)
        cin >> v[i]; 

    TreeNode* node = create(v);
    vector < vector < int > > ans = fun(node); 
    cout << ans.size()<<endl;
    for(auto a : ans) 
    { 
        for(auto b : a)
            cout << b <<" "; 
        cout << endl; 
    }
    return 0;
}