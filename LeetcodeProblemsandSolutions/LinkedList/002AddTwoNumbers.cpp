/*
	You are given two non-empty linked lists representing two non-negative integers. 
	The digits are stored in reverse order, and each of their nodes contains a single digit. 
	Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:
			Input: l1 = [2,4,3], l2 = [5,6,4]
			Output: [7,0,8]

			Explanation: 342 + 465 = 807.
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
	    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) 
	    {
	        ListNode *Last = new ListNode(0);
	        Last->next = NULL;
	        ListNode *Head = Last;
	        int x = 0, y = 0;
	        int iSum = 0, iCarry = 0;
	        
	        while(num1 != NULL || num2 != NULL)
	        {
	            ListNode *newn = new ListNode(0);
	            newn->next = NULL;
                
                x = (num1 != NULL) ? num1->val : 0;
	            y = (num2 != NULL) ? num2->val : 0;
	            
                iSum = (x + y) + iCarry;
	            
	            if(iSum < 10)
	            {
	                newn->val = iSum; 
	                // Erase carry to avoid use of any previous carry value
	                iCarry = 0;
	            }
	            else
	            {
	                newn->val = iSum % 10;
	                iCarry = iSum / 10;
	            }
	            
	            if(num1 != NULL)
                    num1 = num1->next;
	            if(num2 != NULL)
                    num2 = num2->next;
				
	            Last->next = newn;
	            Last = Last->next;
	        }
	    
	        // If there is still a carry remaining then append it to end of list
	        if(iCarry > 0)
	        {
	            ListNode *newn = new ListNode(iCarry);
	            newn->next = NULL; 
	            Last->next = newn;
	            Last = Last->next;
	        }

	        return Head->next;
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
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout<<"\b\b";
}

int main()
{
    ListNode *num1 = NULL;
    ListNode *num2 = NULL;
    vector<int> vctList_1 = {1,2,5,9,6};
    vector<int> vctList_2 = {3,7,5};

    for (int val : vctList_1)
    {
        num1 = push(num1, val);
    }

    for (int val : vctList_2)
    {
        num2 = push(num2, val);
    }

    cout << "\nNum 1: [ ";
    print(num1);
    cout<<" ]"<<endl;

    cout << "\nNum 2: [ ";
    print(num2);
    cout<<" ]"<<endl;

    Solution obSolution;
    num1 = obSolution.addTwoNumbers(num1, num2);
    
    cout << "\nOutput: [ ";
    print(num1);
    cout<<" ]"<<endl;

    return 0;
}

/*
	Num 1: [ 6, 9, 5, 2, 1 ]

	Num 2: [ 5, 7, 3 ]

	Output: [ 1, 7, 9, 2, 1 ]
*/
