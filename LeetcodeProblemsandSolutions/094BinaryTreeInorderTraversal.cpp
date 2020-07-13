#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> vctRet;
		if (NULL == root)
		{
			return vctRet;
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
			vctRet.push_back(curr->val);
			stData.pop();

			curr = curr->right;
		}

		return vctRet;
	}

	vector<int> inorderTraversalR(TreeNode* root)
	{
		vector<int> vctRet;
		if (NULL == root)
		{
			return vctRet;
		}

		vctRet = inorderTraversalR(root->left);
		vctRet.push_back(root->val);
		vector<int> vctRet1;
		vctRet1 = inorderTraversalR(root->right);
		vctRet.insert(vctRet.end(), vctRet1.begin(), vctRet1.end());

		return vctRet;
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
	vector<int> vctRet = objSolution.inorderTraversal(root);
	cout << "Iteravtive norder: " << "\t";
	for (auto it : vctRet)
	{
		cout << it << "\t";
	}

	vector<int> vctRet1 = objSolution.inorderTraversalR(root);
	cout << "\nRecursive Inorder: " << "\t";
	for (auto it : vctRet)
	{
		cout << it << "\t";
	}

	return 0;
}

/*
Inorder:        1       3       2
*/
