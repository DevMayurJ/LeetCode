/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the
next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

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
	bool hasCycle(ListNode *head)
	{
		if (NULL == head)
		{
			return NULL;
		}

		ListNode *slow = head;
		ListNode *fast = head->next;
		while (slow != fast)
		{
			if (fast == NULL || fast->next == NULL)
			{
				return false;
			}

			slow = slow->next;
			fast = fast->next->next;
		}

		return true;
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
	while (temp != NULL && temp->next != head) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

int main()
{
	ListNode *head = NULL;
	std::vector<int> vctList = { 3, 2, 0, -4};

	for (int val : vctList)
	{
		head = push_back(head, val);
	}

	ListNode* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = head;

	cout << "\nGiven linked list \n";
	print(head);


	Solution obSolution;
	bool boRet = obSolution.hasCycle(head);

	cout << "\nCycle=" << boRet;

	return 0;
}

/*
Given linked list
3 2 0
Cycle=1
*/
