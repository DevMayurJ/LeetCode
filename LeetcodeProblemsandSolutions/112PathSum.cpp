/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.

A leaf is a node with no children.
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true

Input: root = [1,2,3], targetSum = 5
Output: false

Input: root = [1,2], targetSum = 0
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

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (NULL == root)
		{
			return false;
		}

		stack<pair<TreeNode*, int>> stTreeSum;
		stTreeSum.push(make_pair(root, targetSum - root->val));
		while (!stTreeSum.empty())
		{
			pair<TreeNode*, int> curr = stTreeSum.top();
			stTreeSum.pop();
			TreeNode*cuurNode = curr.first;
			if (cuurNode->left == NULL && cuurNode->right == NULL && curr.second == 0)
			{
				return true;
			}

			if (NULL != curr.first->left)
			{
				stTreeSum.push(make_pair(cuurNode->left, curr.second - cuurNode->left->val));
			}

			if (NULL != curr.first->right)
			{
				stTreeSum.push(make_pair(cuurNode->right, curr.second - cuurNode->right->val));
			}

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
	TreeNode *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);

	root->right->left = newNode(4);
	root->right->right = newNode(3);
	cout << "Input Binary Tree: ";
	PrintTree(root);
	Solution objSolution;
	cout << "\nOutput: " << objSolution.hasPathSum(root, 6);
	return 0;
}

/*
Input Binary Tree:      [3]     [2]     [4]     [1]     [4]     [2]     [3]
Output: 1
*/

