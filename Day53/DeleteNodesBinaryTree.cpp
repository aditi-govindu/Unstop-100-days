#include <bits/stdc++.h>
using namespace std;

/*
Description: Vikas and Saurav are playing with binary trees and starting take interest in different DFS and BFS algorithms. Given below is the problem statement for one such problem, help Saurav prove to Vikas that this is possible using DFS methods.

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.
*/

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int val)
        {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

vector<Node*> res;
set<int> dp;

// Breadth first traversal of tree
void util (Node* &root)
{
    if(root!=NULL)
    {
        util(root->left);
        util(root->right);
        if(dp.find(root->data)!=dp.end())
        {
            if(root->left)  res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root=NULL;
            delete root;
        }
    }
}

vector<Node*> delNodes(Node* root, vector<int>& to_delete) 
{
    // Delete nodes as specified
    for(int i=0;i<to_delete.size();i++)
        dp.insert(to_delete[i]);
    util(root);
    if(root)
        res.push_back(root);
    return res;
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    // Roots in tree are placed level wise
    queue<Node *> q;
    Node *root = new Node(v[0]);
    q.push(root);
    int i = 1;
    
    while (i < n)
    {
        Node *curr = q.front();
        q.pop();
        if (curr)
        {
            Node *temp1, *temp2;
            if (v[i] != -1)
                temp1 = new Node(v[i]);
            else
                temp1 = nullptr;
            curr->left = temp1;
            q.push(temp1);
            if (i + 1 < n)
            {
                if (v[i + 1] != -1)
                    temp2 = new Node(v[i + 1]);
                else
                    temp2 = nullptr;
                curr->right = temp2;
                q.push(temp2);
            }
            i += 2;
        }
    }

    // Try deletion using DFS
    vector<int> v2;
    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        v2.push_back(x);
    }

    vector<Node*> v3 = delNodes(root, v2);
    for(auto node : v3){
        InOrder(node);
        cout<<endl;
    }
    return 0;
}