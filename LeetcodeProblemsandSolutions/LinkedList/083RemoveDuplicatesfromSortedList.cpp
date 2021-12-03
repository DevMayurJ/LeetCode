/**

Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.
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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (NULL == head)
		{
			return NULL;
		}

		ListNode* curr = head->next;
		ListNode* prev = head;
		while (curr != NULL)
		{
			if (prev->val == curr->val)
			{
				prev->next = curr->next;
				curr = prev->next;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}

		return head;
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
	push(1);
	push(1);
	push(1);

	cout << "Given linked list\n";
	print();

	Solution obSolution;
	head = obSolution.deleteDuplicates(head);

	cout << "\nLinked list after duplecate delete\n";
	print();
	return 0;
}

/*
Given linked list
1 1 1
Linked list after duplecate delete
1
*/
