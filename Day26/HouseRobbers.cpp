/*
Description: Ram has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken 
into on the same night.
Given the root of the binary tree, return the maximum amount of money Ram 
can rob without alerting the police.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
/* Helper function that allocates a 
new node */
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// Function to insert nodes in level order 
Node* insertLevelOrder(vector<string> arr, int i) 
{ 
    // Base case for recursion
    int n=arr.size(); 
    if(i>=n)
    {
        return NULL;
    }
    if(arr[i]=="null")
    {
        return NULL;
    }
    int data= stoi(arr[i]);
    Node* root=newNode(data);
    root->right= insertLevelOrder(arr,2*i+2);
    root->left = insertLevelOrder(arr,2*i+1);
    return root;
} 
// convert string to int
int stoi(string& s){
        stringstream geek(s);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;
    return x;
}
// print final answer
void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<Node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) 
    {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        q.pop();
        if(node==NULL){
            cout<<"null ";
            continue;
        }else{
            cout << node->data << " ";
        }
        if(node->left==NULL and node->right==NULL){
            continue;
        }
        q.push(node->left);
        q.push(node->right);
    }
}

int minSwaps (string s) 
{
    int stack_size = 0;
    for (int i = 0; i < s.length (); i++) 
    {
        char ch = s[i];
        if (ch == '[')
            stack_size++;
        else 
        {
            if (stack_size > 0)
                stack_size--;
        }
    }
    return (stack_size + 1) / 2;
}

unordered_map<Node*, int> dp;
int rob(Node* root) 
{
    if(!root) return 0;
    if(dp.count(root)) return dp[root];
    int dontRob = rob(root -> left) + rob(root -> right), robRoot = root -> data;
    if(root -> left) robRoot += rob(root -> left -> left) + rob(root -> left -> right);
    if(root -> right) robRoot += rob(root -> right -> left) + rob(root -> right -> right);
    return dp[root] = max(dontRob, robRoot);
}

void solve()
{
  std::vector<string> v;
    string a;
    while(cin>>a){
            v.push_back(a);
    }

    Node* base=insertLevelOrder(v,0);
    cout<<rob(base);
}

signed main()
{ 
	ios_base::sync_with_stdio(false); 
    solve();
    
    return 0;
}