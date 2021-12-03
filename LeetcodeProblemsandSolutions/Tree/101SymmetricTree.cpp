/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
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
	bool IsSymmetricUtil(TreeNode* root1, TreeNode* root2)
	{
		if (NULL == root1 && NULL == root2)
		{
			return true;
		}

		if (NULL == root1 || NULL == root2)
		{
			return false;
		}

		return (root1->val == root2->val) &&
			IsSymmetricUtil(root1->left, root2->right) &&
			IsSymmetricUtil(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root)
	{
		return IsSymmetricUtil(root, root);
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
	cout << "\nOutput: " << objSolution.isSymmetric(root);
	return 0;
}

/*
Input Binary Tree:      [3]     [2]     [4]     [1]     [4]     [2]     [3]
Output: 1
*/