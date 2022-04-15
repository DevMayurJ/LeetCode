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

class Solution {
public:
	ListNode* reverseList_Itr(ListNode* head)
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

	ListNode* reverseList(ListNode* head)
	{
		if (NULL == head || NULL == head->next)
		{
			return head;
		}

		ListNode* currNode = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return currNode;
	}
};

ListNode* push(ListNode* head, int data)
{
	ListNode* temp = new ListNode(data);
	temp->next = head;
	head = temp;
	return head;
}

void print(ListNode* head)
{
	ListNode* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

ListNode* CreateList()
{
	ListNode* head = NULL;

	head = push(head, 20);
	head = push(head, 4);
	head = push(head, 15);
	head = push(head, 85);
	return head;
}

int main()
{
	/* Start with the empty list */
	ListNode* head = NULL;
	head = CreateList();

	cout << "Given linked list\n";
	print(head);

	Solution obSolution;
	head = obSolution.reverseList(head);

	cout << "\nReversed Linked list \n";
	print(head);

	head = NULL;
	head = CreateList();

	cout << "\nGiven linked list\n";
	print(head);

	head = obSolution.reverseList_Itr(head);

	cout << "\nReversed Linked list Itrative \n";
	print(head);

	return 0;
}

/*
Given linked list
85 15 4 20
Reversed Linked list
20 4 15 85
Given linked list
85 15 4 20
Reversed Linked list Itrative
20 4 15 85
*/
