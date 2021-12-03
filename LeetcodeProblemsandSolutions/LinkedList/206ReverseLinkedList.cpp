/**

Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#include<iostream>
using namespace std;

 //Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *head = NULL;

class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode *curr = head;
		ListNode *prev = NULL;
		ListNode *next = NULL;

		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev;
	}
};

void push(int data)
{
	ListNode* temp = new ListNode(data);
	temp->next = head;
	head = temp;
}

void print()
{
	ListNode* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}


int main()
{
	/* Start with the empty list */
	push(20);
	push(4);
	push(15);
	push(85);

	cout << "Given linked list\n";
	print();

	Solution obSolution;
	head = obSolution.reverseList(head);

	cout << "\nReversed Linked list \n";
	print();
	return 0;
}

/*
Given linked list
85 15 4 20
Reversed Linked list
20 4 15 85
*/
