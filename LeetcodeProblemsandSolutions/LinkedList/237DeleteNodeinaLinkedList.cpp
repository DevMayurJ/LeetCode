/*
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.



Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
Example 3:

Input: head = [1,2,3,4], node = 3
Output: [1,2,4]
Example 4:

Input: head = [0,1], node = 0
Output: [1]
Example 5:

Input: head = [-3,5,-99], node = -3
Output: [5,-99]
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
	void deleteNode(ListNode* node)
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main()
{
	vector<vector<int>> vctList1 = {
		{4,5,1,9},
		{4,5,1,9},
		{1,2,3,4},
		{0,1},
		{-3,5,-99},
	};


	vector<int> vctList2 = {5, 1, 3, 0, -3};

	for (int i = 0; i < vctList1.size(); ++i)
	{
		ListNode *head1 = NULL;
		for (int val : vctList1[i])
		{
			head1 = push_back(head1, val);
		}

		cout << "\nGiven linked list1 \n";
		print(head1);
		cout << "\nDeliting node with value=" << vctList2[i] << endl;

		Solution obSolution;
		obSolution.deleteNode(GetNode(head1, vctList2[i]));

		cout << "\Output Linked list \n";
		print(head1);
	}

	return 0;
}

/*
Given linked list1
4 5 1 9
Deliting node with value=5
Output Linked list
4 1 9
Given linked list1
4 5 1 9
Deliting node with value=1
Output Linked list
4 5 9
Given linked list1
1 2 3 4
Deliting node with value=3
Output Linked list
1 2 4
Given linked list1
0 1
Deliting node with value=0
Output Linked list
1
Given linked list1
-3 5 -99
Deliting node with value=-3
Output Linked list
5 -99
*/
