/**

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place.
The blue edges and nodes in the above figure indicate the result.

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


class Solution
{
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
	{
		if (list1 == NULL)
		{
			return list2;
		}

		if (list2 == NULL)
		{
			return NULL;
		}

		ListNode* prev = list1;
		int i = 1;
		while (i < a && NULL != prev)
		{
			prev = prev->next;
			++i;
		}

		if (prev == NULL)
		{
			return NULL;
		}

		ListNode* largeNext = prev;
		while (i <= b + 1 && NULL != largeNext)
		{
			largeNext = largeNext->next;
			++i;
		}

		prev->next = list2;
		while (prev->next != NULL)
		{
			prev = prev->next;
		}

		prev->next = largeNext;
		if (0 == a)
		{
			list1 = list2;
		}

		return list1;
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

int main()
{
	ListNode *headA = NULL;
	ListNode *headB = NULL;
	std::vector<int> vctListA = {5,4,3,2,1,0};

	for (int val : vctListA)
	{
		headA = push(headA, val);
	}

	std::vector<int> vctListB = {1000002, 1000001, 1000000 };
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
	ListNode *output = obSolution.mergeInBetween(headA, 3, 4, headB);
	print(output);
}

/*
Given linked list
0 1 2 3 4 5
Given linked list
1000000 1000001 1000002
Output:
0 1 2 1000000 1000001 1000002 5
*/
