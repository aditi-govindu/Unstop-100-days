#include <bits/stdc++.h>
using namespace std;
  
/*
Description: Pushpendra is an engineering student, who has been trying to solve a sequence and series problem. However he was sleeping when the online classes were taken and his younger sister was helping him take notes and has tried her best to take down everything. But due to the teacher repeating then numbers in the list repeatedly she has taken down some numbers multiple times. Now pushpendra wants to remove all the duplicates from his list in order to better understand the concept and not get confused any further.

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

class ListNode 
{ 
    public:
        int val; 
        ListNode* next;
        ListNode(int a)
        {
            val = a;
            next = NULL;
        } 
}; 

void insertNode(ListNode* &head,int val) 
{
    ListNode* newNode = new ListNode(val);
    // Create linked list
    if(head == NULL) 
    {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while(temp->next != NULL)
     temp = temp->next;
    
    temp->next = newNode;
    return;
}

void printList(ListNode *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->val<<" "; 
        node = node->next; 
    } 
}

ListNode* deleteDuplicates(ListNode* head) 
{
    if(!head)
        return 0;
    if(!head -> next)
        return head;
    int val = head ->val;
    ListNode *temp = head -> next;

    // Recursively call delete if current node is unique
    if(temp -> val != val)
    {
        head -> next = deleteDuplicates(temp);
        return head;
    }
    else
    {
        // Skip current node
        while(temp && temp -> val == val)
        {
            ListNode *p = temp;
            temp = temp->next;
            delete p;
        }
        return deleteDuplicates(temp);
    }
}
 
// Driver code
int main() 
{ 
    ListNode* a = NULL; 
    ListNode* res = NULL;
    int n, temp;
    cin>>n;
    while(n--){
        cin>>temp;
        insertNode(a, temp);
    }
    res = deleteDuplicates(a);
    printList(res);
    return 0; 
}