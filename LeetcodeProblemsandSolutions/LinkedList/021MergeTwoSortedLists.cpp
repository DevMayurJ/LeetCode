/**

Merge two sorted linked lists and return it as a sorted list.
The list should be made by splicing together the nodes of the first two lists.
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(INT_MIN);
		ListNode *tail = dummy;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				tail->next = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				l2 = l2->next;
			}

			tail = tail->next;
		}

		if (l1 != NULL)
		{
			tail->next = l1;
		}

		if (l2 != NULL)
		{
			tail->next = l2;
		}

		return dummy->next;
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
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	std::vector<int> vctList1 = { 1,2,4 };
	std::vector<int> vctList2 = { 1,3,4 };

	for (int val : vctList1)
	{
		head1 = push_back(head1, val);
	}

	for (int val : vctList2)
	{
		head2 = push_back(head2, val);
	}

	cout << "\nGiven linked list1 \n";
	print(head1);
	cout << "\n list2 \n";
	print(head2);

	Solution obSolution;
	head1 = obSolution.mergeTwoLists(head1, head2);

	cout << "\nMerged Linked list \n";
	print(head1);

	return 0;
}

/*
Given linked list1
1 2 4
 list2
1 3 4
Merged Linked list
1 1 2 3 4 4
*/


