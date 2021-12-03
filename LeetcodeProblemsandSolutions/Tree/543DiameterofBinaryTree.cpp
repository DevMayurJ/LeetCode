#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*
543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/


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
	int maxDepth(TreeNode* node, int &iMaxD)
	{
		if (node == NULL)
			return 0;
		else
		{
			/* compute the depth of each subtree */
			int lDepth = maxDepth(node->left, iMaxD);
			int rDepth = maxDepth(node->right, iMaxD);
			iMaxD = std::max(iMaxD, lDepth + rDepth);
			/* use the larger one */
			if (lDepth > rDepth)
				return(lDepth + 1);
			else return(rDepth + 1);
		}
	}

	int diameterOfBinaryTree(TreeNode* root)
	{
		int iDiameter = 0;
		maxDepth(root, iDiameter);
		return iDiameter;
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
	cout << "Input Binary Tree(Inorder): ";
	PrintTree(root);
	Solution objSolution;
	cout << "\nDiameter Of Binary Tree: " << objSolution.diameterOfBinaryTree(root);
	return 0;
}

/*
Input Binary Tree(Inorder):     [15]    [9]     [3]     [20]    [7]
Diameter Of Binary Tree: 4
*/

