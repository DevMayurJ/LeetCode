/*
    Given a linked list swap every adjacent nodes and return its head.
    The data in nodes is not to be changed rather each node should be swapped (Swap links of node pairs).

    Example:
            Input : head = [1,2,3,4]
            Output: [2,1,4,3]
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
        ListNode* swapPairs(ListNode* Head) 
        {
            // Empty or only one node in linked list
            if( Head == NULL || Head->next == NULL)
            {
                return Head;
            }
            
            ListNode *Temp = NULL, *Prev = Head, *Curr = Head;
            ListNode* newHead = Head->next;
            
            while(Curr != NULL && Curr->next != NULL)
            {
                // Swap node links
                Temp = Curr->next->next;
                Curr->next->next = Curr;
                Prev->next = Curr->next;	// Very important
                Curr->next = Temp;
                
                // Maintain previous Head to connect next pair with the one before it
                Prev = Curr;
                // Move forward to next pair
                Curr = Curr->next;
            }
            
            return newHead;
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
    std::vector<int> vctList = {11,21,51,101,121 };

    for (int val : vctList)
    {
        head = push(head, val);
    }

    cout << "\nGiven linked list \n";
    print(head);

    Solution obSolution;
    
    head = obSolution.swapPairs(head);
    cout << "\nList after swapping nodes in pairs:\n";
    print(head);

    cout<<endl;
    return 0;
}

/*
    Output:
            Given linked list 
            121 101 51 21 11 
            List after swapping nodes in pairs:
            101 121 21 51 11
*/
