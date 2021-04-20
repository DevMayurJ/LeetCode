/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
class Solution {
public:
	bool isValidBSTPreOrd(TreeNode* root, TreeNode** prev)
	{
		if (NULL == root)
		{
			return true;
		}

		if (!isValidBSTPreOrd(root->left, prev))
		{
			return false;
		}

		if (NULL != *prev && root->val <= (*prev)->val)
		{
			return false;
		}

		*prev = root;
		return isValidBSTPreOrd(root->right, prev);

	}

	bool isValidBST(TreeNode* root)
	{
		TreeNode* prev = NULL;
		//In case of InOrder Tree traversal elemets are ascending sorted for BST.
		//So we are comparing element and it's prev element

		return isValidBSTPreOrd(root, &prev);
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
	TreeNode *root = newNode(3);

	root->left = newNode(9);
	root->right = newNode(20);
	root->left->left = newNode(15);

	root->right->right = newNode(7);
	cout << "Input Binary Serach Tree: ";
	PrintTree(root);
	Solution objSolution;
	cout << "\nOutput: " << objSolution.isValidBST(root);
	return 0;
}

/*
Input Binary Serach Tree:       [15]    [9]     [3]     [20]    [7]
Output: 0
*/