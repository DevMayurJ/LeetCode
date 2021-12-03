/**

Given the head of a singly linked list, reverse the list, and return the reversed list.
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

class Solution 
{
	private:
		ListNode* reverseList(ListNode *head)
		{
		    ListNode *next = NULL, *prev = NULL, *curr = head;
		    
		    while(curr != NULL)
		    {
		        next = curr->next;
		        curr->next = prev;
		        prev = curr;
		        curr = next;
		    }
		    return prev;
		}

	public:
		// sending refrence of head is very important here
		bool Check(ListNode* &head, ListNode *NextNode)
		{
			if (NULL == NextNode)
			{
				return true;
			}

			bool boRet = Check(head, NextNode->next);
			if (head->val != NextNode->val)
			{
				return false;
			}

			head = head->next;
			return boRet;
		}

		bool isPalindrome(ListNode* head)
		{
			return Check(head, head);
		}
		
		// Iterative approach
		bool isPalindrome_SD(ListNode* head) 
		{
		    if(NULL == head)
		    {
		        return false;
		    }
		    
		    ListNode *temp = head;
		    ListNode *tempHead = head->next;
		    
		    // In this approach first we will first find middle of linked list
		    // then reverse the 2nd half of list and compare data of 1st half and 2nd half

			// Get middle of list
		    while(tempHead != NULL && tempHead->next != NULL)
		    {
		        tempHead = tempHead->next->next;
		        temp = temp->next;
		    }
		    
		    temp->next = reverseList(temp->next);	// Reverse 2nd half and Append it to 1st half of list
		    temp = temp->next;
		    
		    tempHead = head;
		    
		    // Compare data of both halves and check if palindrome or not
		    while(temp != NULL)
		    {
		        if(tempHead->val != temp->val) 
		        {
		            break;
		        }
		        temp = temp->next;
		        tempHead = tempHead->next;
		    }
		    
		    if(NULL == temp)
		    {
		        return true;
		    }
		    
		    return false;
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
	push(1);
	push(2);
	push(2);
	push(1);

	cout << "Given linked list\n";
	print();

	Solution obSolution;
	bool boRet = obSolution.isPalindrome(head);

	cout << "\nIs Palindrome Linked list \t" << boRet;
	return 0;
}

/*
Given linked list
1 2 2 1
Is Palindrome Linked list       1
*/
