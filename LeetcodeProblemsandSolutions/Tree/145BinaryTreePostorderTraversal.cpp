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
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> vctRet;
		if (NULL == root)
		{
			return vctRet;
		}

		vector<int> vctLeft = postorderTraversal(root->left);
		vctRet.insert(vctRet.end(), vctLeft.begin(), vctLeft.end());


		vector<int> vctRight = postorderTraversal(root->right);
		vctRet.insert(vctRet.end(), vctRight.begin(), vctRight.end());

		vctRet.push_back(root->val);

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
	vector<int> vctRet = objSolution.postorderTraversal(root);
	cout << "\nRecursive Postorder: " << "\t";
	for (auto it : vctRet)
	{
		cout << it << "\t";
	}

	return 0;
}

/*

Recursive Postorder:    3       2       1
*/
