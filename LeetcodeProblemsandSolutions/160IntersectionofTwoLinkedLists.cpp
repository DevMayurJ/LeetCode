#include<iostream>
#include<vector>
using namespace std;
/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.

*/

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (NULL == headA || NULL == headB)
		{
			return NULL;
		}

		ListNode* tempA = headA;
		ListNode* tempB = headB;
		while (tempA != tempB)
		{
			if (tempA == NULL)
			{
				tempA = headB;
			}
			else
			{
				tempA = tempA->next;
			}

			if (tempB == NULL)
			{
				tempB = headA;
			}
			else
			{
				tempB = tempB->next;
			}
		}

		return tempA;

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

void InterSect(ListNode* headA, ListNode* headB, int iPos1, int iPos2)
{
	int i = 0;
	while (headA != NULL && i < iPos1)
	{
		headA = headA->next;
		++i;
	}

	i = 0;
	while (headB != NULL && i < iPos2)
	{
		headB = headB->next;
		++i;
	}

	headA->next = headB;
}

int main()
{
	ListNode *headA = NULL;
	ListNode *headB = NULL;
	std::vector<int> vctListA = { 4,1,8,4,5 };

	for (int val : vctListA)
	{
		headA = push(headA, val);
	}

	std::vector<int> vctListB = { 5,6,1,8,4,5 };
	for (int val : vctListB)
	{
		headB = push(headB, val);
	}

	cout << "\nGiven linked list \n";
	print(headA);

	cout << "\nGiven linked list \n";
	print(headB);

	cout << "\nOutput:\n";
	Solution obSolution;
	ListNode *intersect = obSolution.getIntersectionNode(headA, headB);
	if (intersect)
	{
		cout << "[" << intersect ->val << "]";
	}
	else
	{
		cout << "NULL";

	}
	
	InterSect(headA, headB, 2, 2);

	cout << "\nOutput after intersection:\n";
	ListNode *intersect1 = obSolution.getIntersectionNode(headA, headB);
	if (intersect1)
	{
		cout << "[" << intersect1->val << "]";
	}
	else
	{
		cout << "NULL";

	}

	return 0;
}

/*

Given linked list
5 4 8 1 4
Given linked list
5 4 8 1 6 5
Output:
NULL
Output after intersection:
[8]

*/
