

/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

#include<iostream>
#include<vector>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head)
        {
            return NULL;
        }

        int iLength = 1;
        ListNode* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            ++iLength;
        }

        k = k % iLength;
        temp->next = head;  //last node linked to head. Now we have to break LL
        int iEnd = iLength - k;//breaking point of list
        while (iEnd > 0)
        {
            --iEnd;
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

void print(ListNode* head)
{
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

ListNode* push_back(ListNode* head, int data)
{
    ListNode* temp = new ListNode(data);

    if (head)
    {
        ListNode* curr = head;
        while (curr->next != nullptr)
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

void Test1()
{
    ListNode* head = NULL;
    std::vector<int> vctList = { 1,2,3,4,5 };

    for (int val : vctList)
    {
        head = push_back(head, val);
    }

    cout << "\nGiven linked list \n";
    print(head);


    Solution obSolution;
    head = obSolution.rotateRight(head, 2);

    cout << "\nOutput Rotated linked list \n";
    print(head);
}
int main()
{
    Test1();
    return 0;
}

/*
Given linked list
1 2 3 4 5
Output Rotated linked list
4 5 1 2 3
*/