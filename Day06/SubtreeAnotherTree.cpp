/*
Description: Marco is fond of story books. 
He is currently reading a very interesting book where there is a concept of parallel world. 
Two worlds will be called parallel if one world is completely a subpart of the other one in terms of structure and the value. The worlds have countries which are connected with each other in the form of a tree. 
Marco is curious that whether the World B is parallel world to World A or not.
*/

#include<bits/stdc++.h>
using namespace std;

string s;
int N,M;
vector<string> WorldA,WorldB;

struct Node {
    int data; 
    Node* left, * right; 
}; 
  
/* Helper function that allocates a 
new node */
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// Function to insert nodes in level order 
Node* insertNodes(vector<string> arr, int i) {
    // Base case for recursion
    int n=arr.size(); 

    if(i >= n) {
    	return NULL;
    }

    if(arr[i] == "null") {
    	return NULL;
    }

    int data= stoi(arr[i]);
    Node* root=newNode(data);
    root->right= insertNodes(arr,2*i+2);
    root->left = insertNodes(arr,2*i+1);

    return root;
} 
// convert string to int
int stoi(string& s) {
	stringstream geek(s);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;

    geek >> x;

    return x;
}

// Function for checking whether they are identical or not
bool isidentical(Node* root1,Node* root2) {
	
    if(root1 == NULL or root2 == NULL)
        return root1 == root2;
    if(root1->data != root2->data)
        return false;
        
	return isidentical(root1->left,root2->left) and isidentical(root1->right,root2->right);
} 

// Main solving function
bool isParallel(Node* root, Node* subRoot) {
    if(root == NULL)
      return false;
    if(root->data == subRoot->data)
        if(isidentical(root,subRoot))
           return true;
   return isParallel(root->left,subRoot) or isParallel(root->right,subRoot);
}

int main(){ 
    // Taking inputs
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> s;
        WorldA.push_back(s);
    }

    cin >> M;

    for(int i=0;i<M;i++) {
        cin >> s;
        WorldB.push_back(s);
    }
	
    // Construction of Tree
    Node* A = insertNodes(WorldA,0);
    Node* B = insertNodes(WorldB,0);
    
    int ans = isParallel(A,B);

    if(ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
} 