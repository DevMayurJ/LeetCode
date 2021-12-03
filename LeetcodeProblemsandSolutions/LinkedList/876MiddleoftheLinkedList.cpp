/**

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.
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
		ListNode* middleNode(ListNode* head)
		{
			if (NULL == head)
			{
				return NULL;
			}

			ListNode* slow = head;
			ListNode* fast = head;
			while (fast != NULL && NULL != fast->next)
			{
				slow = slow->next;
				fast = fast->next->next;
			}

			return slow;
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
	std::vector<int> vctList = { 5,4,3,2,1};;

	for (int val : vctList)
	{
		head = push(head, val);
	}

	cout << "\nGiven linked list \n";
	print(head);

	Solution obSolution;
	ListNode *middle = obSolution.middleNode(head);

	cout << "\n Linked list from middle\n";
	print(middle);

	return 0;
}

/*
Given linked list
1 2 3 4 5
 Linked list from middle
3 4 5
*/
