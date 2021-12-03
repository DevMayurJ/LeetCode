/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int countNodes_R(TreeNode* root)
	{
		int iRet = 1;             //Node itself should be counted
		if (NULL == root)
		{
			return 0;
		}

		iRet += countNodes(root->left);
		iRet += countNodes(root->right);
		return iRet;
	}

	int countNodes(TreeNode* root)
	{
		if (NULL == root)
		{
			return 0;
		}

		queue<TreeNode *> q;
		q.push(root);
		int iRet = 0;
		while (!q.empty())
		{
			TreeNode* temp = q.front();
			q.pop();
			++iRet;

			if (temp->left)
			{
				q.push(temp->left);
			}

			if (temp->right)
			{
				q.push(temp->right);
			}
		}

		return iRet;
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
	TreeNode *root = newNode(1);

	root->right = newNode(2);
	root->right->left = newNode(3);

	Solution objSolution;
	int iRet = objSolution.countNodes(root);
	cout << "Iteravtive countNodes: " << "\t" << iRet << endl;
	iRet = objSolution.countNodes_R(root);
	cout << "Recursive countNodes: " << "\t" << iRet << endl;
	return 0;
}

/*
Iteravtive countNodes:  3
Recursive countNodes:   3
*/
