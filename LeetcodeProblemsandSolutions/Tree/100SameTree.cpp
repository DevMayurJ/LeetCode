/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2,1], q = [1,1,2]
Output: false
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* newNode(int data)
{
	TreeNode* Node = new TreeNode();
	Node->val = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (NULL == p && NULL == q)
        {
            return true;
        }
        
        if (NULL == p || NULL == q)
        {
            return false;
        }
        
        if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        {
            return true;
        }
        
        return false;        
    }
};

void PrintTree(TreeNode* root)
{
	if (NULL == root)
	{
		return;
	}

	TreeNode* curr = root;
	stack<TreeNode *> stData;
	while (NULL != curr || !stData.empty())
	{
		while (curr != NULL)
		{
			stData.push(curr);
			curr = curr->left;
		}

		curr = stData.top();
		cout << "\t[" << curr->val << "]";
		stData.pop();

		curr = curr->right;
	}
}

int main()
{
	TreeNode *root1 = newNode(1);

	root1->left = newNode(2);
	root1->right = newNode(2);
	root1->left->left = newNode(3);
	root1->left->right = newNode(4);

	root1->right->left = newNode(4);
	root1->right->right = newNode(3);

	TreeNode *root2 = newNode(1);

	root2->left = newNode(2);
	root2->right = newNode(2);
	root2->left->left = newNode(3);
	root2->left->right = newNode(4);

	root2->right->left = newNode(4);
	root2->right->right = newNode(3);

	cout << "Input Binary Tree1: ";
	PrintTree(root1);
    cout << "\nInput Binary Tree2: ";
	PrintTree(root2);
	Solution objSolution;
	cout << "\nOutput isSameTree: " << objSolution.isSameTree(root1, root2);
	return 0;
}

/*
Input Binary Tree1:     [3]     [2]     [4]     [1]     [4]     [2]     [3]
Input Binary Tree2:     [3]     [2]     [4]     [1]     [4]     [2]     [3]
Output isSameTree: 1
*/