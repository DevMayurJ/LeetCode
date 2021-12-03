/**

Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.
*/

#include<iostream>
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

ListNode *head = NULL;

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (NULL == head)
		{
			return NULL;
		}

		//Create Dummy node is main trick so that we can start from dummy and head node
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* curr = dummy;
		while (curr->next != NULL && curr->next->next != NULL) //min two nodes require for compare
		{
			int iCurrVal;
			if (curr->next->val == curr->next->next->val)// check if above not NULL nodes have same value.
			{
				iCurrVal = curr->next->val;
				while (curr->next != NULL && curr->next->val == iCurrVal)
				{
					//curr->next = curr->next->next;
					ListNode* temp = curr->next;
					curr->next = curr->next->next;
					if (NULL != temp)
					{
						//Value same. Unlink  cur->next. Not working on leetcode compire. VCC able to free
						free(temp);
					}
				}
			}
			else
			{
				//Value not same. Move to next node.
				curr = curr->next;
			}
		}

		return dummy->next;
	}
};

void push(int data)
{
	ListNode* temp = new ListNode(data);
	temp->next = head;
	head = temp;
}

void print()
{
	ListNode* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}


int main()
{
	/* Start with the empty list */
	//push(1);
	//push(1);
	//push(1);

	//[1, 2, 3, 3, 4, 4, 5]
	push(5); push(4); push(4); push(3); push(3); push(2); push(1);

	cout << "Given linked list\n";
	print();

	Solution obSolution;
	head = obSolution.deleteDuplicates(head);

	cout << "\nLinked list after duplecate delete\n";
	print();
	return 0;
}

/*
Given linked list
1 2 3 3 4 4 5
Linked list after duplecate delete
1 2 5
*/
