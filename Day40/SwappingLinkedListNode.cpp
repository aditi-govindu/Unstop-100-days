#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Description: Ram gave Shyaam a challenge, he gave shyaam the head of a linked list, and an integer k.
He asked Shyaam to swap the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
*/

struct Node
{
    int val;
    struct Node* next;
};

// Assign value to nodes
struct Node* allocateNode(int data)
{
    struct Node* root = new Node;
    root -> val = data;
    root -> next = nullptr;
    return root;
}

void insertNode(Node** root, int data)
{
    Node* temp = allocateNode(data);
    Node* ptr;

    // If head is empty, allocate first node
    if(*root == nullptr)
        *root = temp;
    else
    {
        // Travel to last allocated node and append to end
        ptr = *root;
        while(ptr -> next != nullptr)
            ptr = ptr -> next;
        ptr -> next = temp;
    }
}

struct Node* allocateList(vector<int> data, int n)
{
    // Driver that calls linked list allocation
    struct Node* head = nullptr;
    for(int i = 0; i < n; i++)
        insertNode(&head, data[i]);
    return head;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    cin >> k;
    // Swap values at k places from start and end of list
    int temp = numbers[k - 1];
    numbers[k - 1] = numbers[n - k];
    numbers[n - k] = temp;

    struct Node* h = allocateList(numbers, n);

    // Display expected results to user
    while(h != nullptr)
    {
        cout << h -> val << " ";
        h = h -> next;
    }
    return 0;
}