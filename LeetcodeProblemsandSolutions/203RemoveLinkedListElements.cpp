/*
Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

ListNode * GetNode(ListNode* head, int iVal)
{
	ListNode* temp = head;
	while (temp != NULL && iVal != temp->val)
	{
		temp = temp->next;
	}

	return temp;
}

class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		if (NULL == head)
		{
			return NULL;
		}

		ListNode *prev = new ListNode(INT_MIN);
		prev->next = head;
		while (prev->next != NULL)
		{
			if (prev->next->val == val)
			{
				if (head == prev->next)
				{
					head = head->next;
				}

				prev->next = prev->next->next;
			}
			else
			{
				prev = prev->next;
			}
		}

		return head;
	}
};

int main()
{
	vector<vector<int>> vctList1 = {
		{1,2,6,3,4,5,6},
		{},
		{7,7,7,7},
	};


	vector<int> vctList2 = { 6, 1, 7 };

	for (int i = 0; i < vctList1.size(); ++i)
	{
		ListNode *head1 = NULL;
		for (int val : vctList1[i])
		{
			head1 = push_back(head1, val);
		}

		cout << "\nGiven linked list1 \n";
		print(head1);
		cout << "\nDelitings node with value=" << vctList2[i] << endl;

		Solution obSolution;
		obSolution.removeElements(head1, vctList2[i]);

		cout << "\Output Linked list \n";
		print(head1);
	}

	return 0;
}

/*
Given linked list1
1 2 6 3 4 5 6
Delitings node with value=6
Output Linked list
1 2 3 4 5
Given linked list1

Delitings node with value=1
Output Linked list

Given linked list1
7 7 7 7
Delitings node with value=7
Output Linked list
7 7 7 7
*/
