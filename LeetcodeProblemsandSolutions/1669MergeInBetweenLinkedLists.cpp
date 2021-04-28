/**

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place.
The blue edges and nodes in the above figure indicate the result.

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
	// Returns the node at given position
        // If position not specified then returns the last node  
	ListNode* getNode(ListNode* list, int n = -1)
	{
	    	ListNode *temp = list;
		    
	    	if(n == -1)
	    	{
			while(NULL != temp->next)
			{
				temp = temp->next;
			}
	    	}
	    	else
            	{
		        int i = 0;
		        while(i < n)
		        {
		            temp = temp->next;
		            ++i;
		        }
	    	}
		return temp;
	}
public:
	ListNode* mergeInBetween_MJ(ListNode* list1, int a, int b, ListNode* list2)
	{
		if (list1 == NULL)
		{
			return list2;
		}

		if (list2 == NULL)
		{
			return NULL;
		}

		ListNode* prev = list1;
		int i = 1;
		while (i < a && NULL != prev)
		{
			prev = prev->next;
			++i;
		}

		if (prev == NULL)
		{
			return NULL;
		}

		ListNode* largeNext = prev;
		while (i <= b + 1 && NULL != largeNext)
		{
			largeNext = largeNext->next;
			++i;
		}

		prev->next = list2;
		while (prev->next != NULL)
		{
			prev = prev->next;
		}

		prev->next = largeNext;
		if (0 == a)
		{
			list1 = list2;
		}

		return list1;
	}
	
	ListNode* mergeInBetween_SD(ListNode* list1, int a, int b, ListNode* list2) 
	{
		if(NULL != list1 && NULL != list2)
		{
			// Get last node of 2nd list
			ListNode* p = getNode(list2);
			
			// Get a'th Node
			ListNode* nodeA = getNode(list1, a - 1);
				    
			// We have already traversed the list till nodeA
			// So now we only need to move forward [(b + 1) - a] positions
			ListNode* nodeB = getNode(nodeA, ((b + 1) - a));
				    
			nodeA->next = list2;
			p->next = nodeB->next;
			nodeB->next = NULL;
		}
		return list1;
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
	ListNode *headA = NULL;
	ListNode *headB = NULL;
	std::vector<int> vctListA = {5,4,3,2,1,0};

	for (int val : vctListA)
	{
		headA = push(headA, val);
	}

	std::vector<int> vctListB = {1000002, 1000001, 1000000 };
	for (int val : vctListB)
	{
		headB = push(headB, val);
	}

	cout << "\nGiven linked list \n";
	print(headA);

	cout << "\nGiven linked list \n";
	print(headB);

	Solution obSolution;
	
	cout << "\nOutput(MJ):[";
	ListNode *output = obSolution.mergeInBetween_MJ(headA, 3, 4, headB);
	print(output);
	cout<<"]"<<endl;
	
	/* There is no point in calling the function again because on first call the original lists will be changed
	
	cout<<"\nOutput(SD):[ ";
	ListNode *output = obSolution.mergeInBetween_SD(headA, 3, 4, headB);
	print(output);
	cout<<"]"<<endl;
	*/
}

/*
	Given linked list 
	0 1 2 3 4 5 
	Given linked list 
	1000000 1000001 1000002 
	Output(SD):[ 0 1 2 1000000 1000001 1000002 5 ]
	Output(MJ):[0 1 2 1000000 1000001 1000002 5 ]
*/
