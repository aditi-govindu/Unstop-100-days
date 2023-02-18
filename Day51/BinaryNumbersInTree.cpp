#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

/*
Description: Yash is given the root of a binary tree with 0 or 1 as the value of each node. Starting with the most significant bit, each root-to-leaf path represents a binary number.

If the path is 0 -> 1 -> 1 -> 0 -> 1, for example, this may be 01101 in binary, which is 13.
Consider the numbers represented by the path from the root to each of the tree's leaves.Rohit needs to calculate the total of these numbers.

The test cases are created in such a way that the solution can be stored in a 32-bit integer.
*/

using namespace std;

// Stores final sum of all paths
static int result;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* temp = new Node();
    temp -> data = val;
    temp -> left = nullptr;
    temp -> right = nullptr;
    return temp;
}

Node* createTree(vector<int> values, int i, int n)
{
    // Create binary tree where left child is at 2i + 1 and right child at 2i + 2 index of array
    Node *root = nullptr;
    if(i < n)
    {
        root = createNode(values[i]);
        root -> left = createTree(values, 2*i +1, n);
        root -> right = createTree(values, 2*i + 2, n);
    }
    return root;
} 

void traversePath(Node* root, int path[], int length)
{
    if(root == nullptr)
        return;
    path[length] = root -> data;
    length++;

    // If leaf reached, find decimal value of full path
    if(root -> left == nullptr && root -> right == nullptr)
    {
        int answer = 0;
        for(int i = 0; i < length; i++)
            answer += (path[i]) * (pow(2, length - i - 1));
        result += answer;
    }
    else
    {
        // Search for paths in left and right subtrees
        traversePath(root -> left, path, length);
        traversePath(root -> right, path, length);
    }
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> number(n);
    int answer[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> number[i];
    
    Node* root = createTree(number, 0, n);
    traversePath(root, answer, 0);
    cout << result << endl;
    return 0;
}