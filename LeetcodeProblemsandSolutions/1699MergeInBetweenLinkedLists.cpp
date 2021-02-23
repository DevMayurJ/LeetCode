/**
 *	You are given two linked lists: list1 and list2 of sizes n and m respectively.
 *
 *	Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
 *
 *  Example: Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
 *			 Output: [0,1,2,1000000,1000001,1000002,5]
 *
 */
#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

class Solution 
{
	public:
		ListNode* mergeInBetween(ListNode* start1, int a, int b, ListNode* start2) 
		{
		    if(start1 != NULL && start2 != NULL)
		    {
		    	ListNode* p = getNode(start2);
		        ListNode* nodeA = getNode(start1, a);
		        // We have already traversed the list till nodeA
		        // So now we only need to move forward [(b + 1) - a] positions
		        ListNode* nodeB = getNode(nodeA, ((b + 1) - a) + 1);
		        nodeA->next = start2;
		        p->next = nodeB->next;
		        nodeB->next = NULL;
		    }
		    return start1;
		}
		
		/* Returns the node at given position */
		ListNode* getNode(ListNode* start, int n = -1)
		{
		    ListNode *p = start;
		    // If position not specified then return the last node 
		    if(n == -1)
		    {
		        while(p->next != NULL)
		        {
		        	p = p->next;
		        }
		    }
		    else{
		        int i = 1;
		        while(i < n)
		        {
		            p = p->next;
		            ++i;
		        }
		    }
		    return p;
		}
};

struct ListNode* newNode(int data)
{
	struct ListNode* node = new struct ListNode;
	node->val = data;
	node->next = NULL;
	return node;
};

/* Fill linked list with numbers between given intervals */
void FillList(ListNode* startNode, int start, int end)
{
	ListNode *p = startNode;
	for(int i = start; i <= end; ++i)
	{	
		p->next = newNode(i);
		p = p->next;	
	}
}

/* Print linked list */
void PrintList(ListNode* start)
{
	ListNode* p = start;
	
	do
	{
		cout<<p->val<<", ";
		p = p->next;
	}while(p->next != NULL);
	cout<<p->val;
}
int main()
{		
 	Solution objSolution;
 	int iStart = 0, iEnd = 6;
 	
 	ListNode *start1 = newNode(iStart);
	FillList(start1, iStart + 1,iEnd);
	
	iStart = 100, iEnd = 106;
	ListNode *start2 = newNode(iStart);
	FillList(start2, iStart + 1,iEnd);
	
 	cout<<"\n List 1: [";
 	PrintList(start1);
 	cout<<"]"<<endl;
 	
 	cout<<"\n List 2: [";
	PrintList(start2);
	cout<<"]"<<endl;
	
	int iPos1 = 3, iPos2 = 4;
	cout<<"\n Merge between position "<<iPos1<<" and "<<iPos2<<endl;
	
	start1 = objSolution.mergeInBetween(start1, iPos1, iPos2, start2);
	
	cout<<"\n Output: [";
	PrintList(start1);
	cout<<"]"<<endl;
	
	return 0;
}
/*
	 List 1: [0, 1, 2, 3, 4, 5, 6]

	 List 2: [100, 101, 102, 103, 104, 105, 106]

	 Merge between position 3 and 4

	 Output: [0, 1, 2, 100, 101, 102, 103, 104, 105, 106, 5, 6]
*/
