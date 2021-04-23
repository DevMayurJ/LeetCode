/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

#include<iostream>
#include<vector>
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
	ListNode* oddEvenList(ListNode* head)
	{
		if (NULL == head)
		{
			return NULL;
		}

		//we will split list into two list and then append even list to add list.
		ListNode* oddNode = head;
		ListNode* evenNode = head->next;
		ListNode* evenHead = evenNode;
		while (evenNode != NULL && evenNode->next != NULL)
		{
			oddNode->next = evenNode->next;
			oddNode = oddNode->next;
			evenNode->next = oddNode->next;
			evenNode = evenNode->next;
		}

		oddNode->next = evenHead;
		return head;
	}
};

ListNode* push_back(ListNode* head, int data)
{
	ListNode* temp = new ListNode(data);

	if (head)
	{
		ListNode* curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		curr->next = temp;
	}
	else
	{
		head = temp;
	}

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

int main()
{
	ListNode *head = NULL;
	std::vector<int> vctList = { 1,2,3,4,5 };

	for (int val : vctList)
	{
		head = push_back(head, val);
	}

	cout << "\nGiven linked list \n";
	print(head);

	Solution obSolution;
	head = obSolution.oddEvenList(head);

	cout << "\nOdd-after Even Linked list \n";
	print(head);

	return 0;
}

/*
Given linked list
1 2 3 4 5
Odd-after Even Linked list
1 3 5 2 4
*/

