/*
Description: John wick is trying to escape the island which is present in the form of a linked list consisting of n nodes in an unsorted fashion. To figure out the escape John first has to sort the list and figure out the middle of that list. If the length of the list is even then both the middle points will be the escape. The escape is only possible if he manages to search the middle of that list. If not then he will be on that island forever. Your task is to help John in escaping the island.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1e9 + 7

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


ListNode* middleNode(ListNode* head) {
	// fast and slow pointers 
        ListNode* slow=head;
        ListNode* fast=head;
        
        // running the fast and slow pointers fast pointer with twice the speed and slow with half the speed.
        while(slow and fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // returning slow pointer as it will be the middle.
        return slow;
}

// constructing linked list recursively.
ListNode* constructLL(vector<int>& arr,int si){

	if(si==arr.size()){
		return nullptr;
	}

	ListNode* head=new ListNode(arr[si]);

	ListNode* temp=constructLL(arr,si+1);

	head->next=temp;

	return head;
}

int main(){
	// taking inputs

	int n;
	std::cin>>n;
	vector<int>arr(n);



	for(int i=0;i<n;i++){
		std::cin>>arr[i];
	}

	// sorting the vector.

	sort(arr.begin(),arr.end());

	ListNode* head=constructLL(arr,0);

	ListNode* ans=middleNode(head);

	std::cout<<ans->val<<endl;

 return 0;
}