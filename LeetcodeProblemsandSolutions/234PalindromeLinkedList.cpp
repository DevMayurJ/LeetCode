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
	// sending refrence of head is very important here
	bool Check(ListNode* &head, ListNode *NextNode)
	{
		if (NULL == NextNode)
		{
			return true;
		}

		bool boRet = Check(head, NextNode->next);
		if (head->val != NextNode->val)
		{
			return false;
		}

		head = head->next;
		return boRet;
	}

	bool isPalindrome(ListNode* head)
	{
		return Check(head, head);
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
	push(2);
	push(2);
	push(1);

	cout << "Given linked list\n";
	print();

	Solution obSolution;
	bool boRet = obSolution.isPalindrome(head);

	cout << "\nIs Palindrome Linked list \t" << boRet;
	return 0;
}

/*
Given linked list
1 2 2 1
Is Palindrome Linked list       1
*/
