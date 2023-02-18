/*
Description: Ram gave Shyaam a binary tree root and an integer target, 
he asked Shyaam to delete all the leaf nodes with value target.
Note that once you delete a leaf node with value target, if 
its parent node becomes a leaf node and has the value target, 
it should also be deleted (you need to continue doing that until you cannot).
*/

#include<bits/stdc++.h>
using namespace std;

struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
// Helper function that allocates a new node
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
    if(i>=n){
        return NULL;
    }
    if(arr[i]=="null"){
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

    while (q.empty() == false) {
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
Node* removeLeafNodes(Node* root, int target) 
{
    if (root->left) root->left = removeLeafNodes(root->left, target);
    if (root->right) root->right = removeLeafNodes(root->right, target);
    return root->left == root->right && root->data == target ? nullptr : root;
}


signed main(){ 
    ios_base::sync_with_stdio(false); 

    std::vector<string> v;
    string a;
    bool first=true;
    while(cin>>a)
    {
        if(first)
            v.push_back(a);
    }
    string kk=v.back();
    int k=stoi(kk);
    v.pop_back();
    Node* base=insertLevelOrder(v,0);
    base=removeLeafNodes(base,k);
    printLevelOrder(base);
    return 0;
}