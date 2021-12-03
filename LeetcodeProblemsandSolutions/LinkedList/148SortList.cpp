/**

Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []

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
public:
	ListNode* sortList(ListNode* head)
	{
		//using merge sort for sorting linked list
		if (NULL == head || NULL == head->next)
		{
			return head;
		}

		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* last1 = NULL; // last node of first linked list;
		//find middle of linked list using slow fast technigue
		while (NULL != fast && NULL != fast->next)
		{
			last1 = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		last1->next = NULL; //break two link list at mid point;
		//recusivily split linked list
		ListNode* firstList = sortList(head);
		ListNode* secondList = sortList(slow);

		//use solution of problem21 to merge sorted linked list
		return mergeTwoLists(firstList, secondList);
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
	vector<vector<int>> vctList1 = {
		{4,2,1,3},
		{-1,5,3,4,0 }
		};

	for (int i = 0; i < vctList1.size(); ++i)
	{
		ListNode *head1 = NULL;
		for (int val : vctList1[i])
		{
			head1 = push_back(head1, val);
		}

		cout << "\nGiven linked list1 \n";
		print(head1);

		Solution obSolution;
		head1 = obSolution.sortList(head1);

		cout << "\nsorted Linked list \n";
		print(head1);
	}

	return 0;
}

/*

Given linked list1
4 2 1 3
sorted Linked list
1 2 3 4
Given linked list1
-1 5 3 4 0
sorted Linked list
-1 0 3 4 5
*/


