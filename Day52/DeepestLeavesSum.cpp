#include <bits/stdc++.h>
using namespace std;

// Description: Given the root of a binary tree, return the sum of values of its deepest leaves.

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

// Height of tree
int findLevel(Node *root)
{
    if(root == NULL)    
        return 0;
    return 1 + max(findLevel(root->right), findLevel(root->left));
}

// Add values of leaf nodes
int findSum(Node *root, int level)
{
    if(root == NULL)    
        return 0;
    if(level == 1)  
        return root->data;
    return findSum(root->left, level - 1) + findSum(root->right, level - 1);
}

// If leaf is at deepest level, add to sum
int deepestLeavesSum(Node* root) 
{
    int level = findLevel(root);
    return findSum(root, level);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    queue<Node *> q;
    Node *root = new Node(v[0]);
    q.push(root);
    int i = 1;
    
    while (i < n)
    {
        // Store nodes level wise
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
    cout << endl << deepestLeavesSum(root)<<endl;
    return 0;
}