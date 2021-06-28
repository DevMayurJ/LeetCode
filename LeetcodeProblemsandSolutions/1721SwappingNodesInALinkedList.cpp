/*
	You are given the head of a linked list, and an integer k.
	Return the head of the linked list after swapping the values of the kth node from the beginning 
	and the kth node from the end (the list is 1-indexed).
	
	Input: head = [1,2,3,4,5], k = 2
	Output: [1,4,3,2,5]
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
    ListNode* getKthNode(ListNode* head, ListNode** start, int k)
    {
        ListNode *ptr = new ListNode(0);
        ptr->next = head;
        ListNode* temp = ptr;
        ListNode* tempHead = ptr;

        int iCnt = 1;
        
        while(iCnt <= k+1)
        {
            temp = temp->next;
            if(iCnt == k)
                *start = temp;		// Fill given address with kth node from start
            iCnt++;
        }
            
        while(temp != NULL)
        {
            temp = temp->next;
            tempHead = tempHead->next;
        }
        // return kth node from last
        return tempHead->next;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int temp = 0;
        ListNode* Kth_start = NULL;
        
        ListNode* Kth_end = getKthNode(head, &Kth_start, k);
		
        swap(Kth_start->val, Kth_end->val);     

		return head;
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
	std::vector<int> vctList = { 4,1,8,11,5 };

	for (int val : vctList)
	{
		head = push(head, val);
	}

	cout << "\nGiven linked list \n";
	print(head);

	Solution obSolution;
	
	cout << "\nList after swapping 2nd node from start and end:\n";
	head = obSolution.swapNodes(head, 2);
	print(head);

	cout<<endl;
	return 0;
}

/*
	Given linked list 
	5 11 8 1 4 
	List after swapping 2nd node from start and end:
	5 1 8 11 4 
*/
