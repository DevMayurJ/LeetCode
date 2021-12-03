#include <iostream>
#include <stack>
//#include <pair>
using namespace std;
/*
Given the root of a binary tree, invert the tree, and return its root.
*/

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
	TreeNode* invertTree(TreeNode* root)
	{
		if (root)
		{
			invertTree(root->left);
			invertTree(root->right);
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;

		}

		return root;
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
	cout << "\nInput Tree : " << "\t";
	PrintTree(root);

	Solution objSolution;
	TreeNode *root1 = objSolution.invertTree(root);
	cout << "\ninvertTree : " << "\t";
	PrintTree(root1);

	return 0;
}

/*
Input Tree : [1]     [3]     [2]
invertTree : [2]     [3]     [1]
*/
