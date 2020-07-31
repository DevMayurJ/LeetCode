#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

*/

/*
 * Definition for a binary tree node.*/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	int minDepth(TreeNode* root)
	{
		if (NULL == root)
		{
			return 0;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}

		// If left subtree is NULL, recur for Right subtree 
		if (!root->left)
			return minDepth(root->right) + 1;

		// If right subtree is NULL, recur for left subtree 
		if (!root->right)
			return minDepth(root->left) + 1;

		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = new struct TreeNode;
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main()
{
	//Given binary tree[3, 9, 20, null, null, 15, 7],
	/*/
		  3
		/	\
		9	 20
			/	\
			15   7
			*/

	//TreeNode *root = newNode(1);

	//root->right = newNode(2);
	//root->right->left = newNode(3);

	TreeNode *root = newNode(3);
	root->right = newNode(20);
	root->left = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(7);

	Solution objSolution;
	int iRet = objSolution.minDepth(root);
	cout << "Minimum Depth: " << "\t" << iRet;
	return 0;
}

/*
Minimum Depth:  2
*/
