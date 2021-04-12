#include <iostream>
#include <vector>
#include <stack>
//#include <pair>
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

class Solution
{
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		if (NULL == root1)
		{
			return root2;
		}

		if (NULL == root2)
		{
			return root1;
		}

		root1->val = root1->val + root2->val;
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);

		return root1;
	}

	/*	For debugging
		void PrintLevel(vector<int> vctInp)
		{
			for(auto inp : vctInp)
			{
				cout<<inp<<" ";
			}
		}
	*/
};

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = new struct TreeNode;
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

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

	root->right = newNode(2);
	root->right->left = newNode(3);
	cout << "\nInput Tree : " << "\t";
	PrintTree(root);

	cout << "\nInput Tree : " << "\t";
	PrintTree(root);

	Solution objSolution;
	TreeNode *root1 = objSolution.mergeTrees(root, root);
	cout << "\nmergeTrees : " << "\t";
	PrintTree(root1);

	return 0;
}
