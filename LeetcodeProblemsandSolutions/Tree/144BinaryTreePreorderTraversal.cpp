#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> vctRet;
		if (NULL == root)
		{
			return vctRet;
		}

		vctRet.push_back(root->val);
		vector<int> vctLeft = preorderTraversal(root->left);
		vctRet.insert(vctRet.end(), vctLeft.begin(), vctLeft.end());

		vector<int> vctRight = preorderTraversal(root->right);
		vctRet.insert(vctRet.end(), vctRight.begin(), vctRight.end());

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
	TreeNode* root = newNode(1);

	root->right = newNode(2);
	root->right->left = newNode(3);

	Solution objSolution;
	vector<int> vctRet = objSolution.preorderTraversal(root);
	cout << "\nRecursive Preorder: " << "\t";
	for (auto it : vctRet)
	{
		cout << it << "\t";
	}

	return 0;
}

/*

Recursive Preorder:     1       2       3
*/
