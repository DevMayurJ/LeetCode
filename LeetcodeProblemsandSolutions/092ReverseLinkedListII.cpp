/**

Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.
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

public:

	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (m == n)
			return head;

		// revs and revend is start and end respectively
		// of the portion of the linked list which
		// need to be reversed. revs_prev is previous
		// of starting position and revend_next is next
		// of end of list to be reversed.
		ListNode* revs = NULL, *revs_prev = NULL;
		ListNode* revend = NULL, *revend_next = NULL;

		// Find values of above pointers.
		int i = 1;
		ListNode* curr = head;
		while (curr && i <= n)
		{
			if (i < m)
				revs_prev = curr;

			if (i == m)
				revs = curr;

			if (i == n)
			{
				revend = curr;
				revend_next = curr->next;
			}

			curr = curr->next;
			i++;
		}

		revend->next = NULL;

		// Reverse linked list starting with
		// revs.
		revend = reverseList(revs);

		// If starting position was not head
		if (revs_prev)
			revs_prev->next = revend;

		// If starting position was head
		else
			head = revend;

		revs->next = revend_next;
		return head;
	}

	ListNode* reverseBetween_MJ(ListNode* head, int left, int right)
	{
		ListNode *curr = head;
		ListNode *prev = head;
		ListNode *start = NULL;
		ListNode *end = NULL;
		int i = 1;

		while (curr != NULL && i <= right)
		{
			if (i < left)
			{
				prev = curr;
			}
			else if (i == left)
			{
				start = curr;
			}
			else if (i == right)
			{
				end = curr->next;

				//reverse part of linked list.
				curr->next = NULL;
				ListNode *subhead = reverseList(start);
				if (1 == left)
				{
					//update head node.
					head = subhead;
				}

				//Insert linked list
				prev->next = subhead;
				start->next = end;
				break;
			}

			++i;
			curr = curr->next;
		}

		return head;
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
	ListNode *head = NULL;
	std::vector<int> vctList = { 4,1,8,11,5 };

	for (int val : vctList)
	{
		head = push(head, val);
	}

	cout << "\nGiven linked list \n";
	print(head);

	Solution obSolution;
	head = obSolution.reverseBetween(head, 2, 4);

	cout << "\nReversed Linked list \n";
	print(head);

	ListNode *headMJ = NULL;
	std::vector<int> vctList1 = { 4,1,8,11,5 };

	for (int val : vctList1)
	{
		headMJ = push(headMJ, val);
	}

	cout << "\nGiven linked list \n";
	print(headMJ);

	//Solution obSolution;
	headMJ = obSolution.reverseBetween(headMJ, 2, 4);

	cout << "\nReversed Linked list(MJ) \n";
	print(headMJ);

	return 0;
}

