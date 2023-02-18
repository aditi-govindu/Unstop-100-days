#include<bits/stdc++.h>
using namespace std;

/*
Description: You are given the root of two trees . You have to tell whether it is possible to make two trees equal after performing Operation(any number of times).

Operation is defined in such a way that you can swap left subtree and right subtree .

All values in the nodes are unique.

Return True if it is possible to make two trees equal ,otherwise False

-1 value present in level order traversal represents the NULL at that location.

1 2 3 4 -1 -1 5

Level Order traversal - 1 2 3 4 null null 5
*/

class Node
{
    public:
        int val;
        Node *left,*right;

        // Constructor to initialize node values
        Node(int x)
        {
            val=x;
            left=NULL;
            right=NULL;
        }
};

Node* buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == ' ')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) 
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "-1") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "-1") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

bool isAlmostEqualTree(Node *root1,Node *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    
    if((root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL)||(root1->val!=root2->val))
        return false;
    
    if(root1->val==root2->val && (isAlmostEqualTree(root1->left,root2->right)||(isAlmostEqualTree(root1->left,root2->left)))&&(isAlmostEqualTree(root1->right,root2->right)||(isAlmostEqualTree(root1->right,root2->left))))
        return true;
    
    return false;
}

int main()
{
    string a,b;
    getline(cin,a);
    Node *root1= buildTree(a);
    getline(cin,b);
    Node *root2= buildTree(b);
    if(isAlmostEqualTree(root1,root2))
    cout<<"true";
    else
    cout<<"false";
    return 0;
}