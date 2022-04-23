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
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		//needed dummy node if n is length of ll
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode* fast = dummy;
		ListNode* slow = dummy;
		for (int i = 0; i < n; ++i)
		{
			fast = fast->next;
		}

		while (fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}

		slow->next = slow->next->next;
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
	vector<vector<int>> vctList1 = {
		{1,2,3,4,5},
		{1},
		{1,2}
	};

	vector<int> vctPosition = {2,1,1};

	for (int i = 0; i < vctList1.size(); ++i)
	{
		ListNode* head1 = NULL;
		for (int val : vctList1[i])
		{
			head1 = push_back(head1, val);
		}

		cout << "\nGiven linked list1 \n";
		print(head1);
		cout << "\nPosition of node delete: " << vctPosition[i] << "\n";

		Solution obSolution;
		head1 = obSolution.removeNthFromEnd(head1, vctPosition[i]);

		cout << "\nLinked list after deletion\n";
		print(head1);
	}

	return 0;
}

/*
Given linked list1
1 2 3 4 5
Position of node delete: 2

Linked list after deletion
1 2 3 5
Given linked list1
1
Position of node delete: 1

Linked list after deletion

Given linked list1
1 2
Position of node delete: 1

Linked list after deletion
1
*/



