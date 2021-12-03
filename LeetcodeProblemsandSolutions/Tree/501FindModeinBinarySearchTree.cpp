#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
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

class Solution
{
public:
	vector<int> findMode(TreeNode* root)
	{
		int iMaxCnt = 0;
		map<int, int> mDataToCnt;
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
			auto it = mDataToCnt.find(curr->val);
			if (it == mDataToCnt.end())
			{
				mDataToCnt[curr->val] = 1;
			}
			else
			{
				it->second += 1;
			}

			if (iMaxCnt < mDataToCnt[curr->val])
			{
				iMaxCnt = mDataToCnt[curr->val];
			}

			cout << "\t" << curr->val;
			stData.pop();
			curr = curr->right;
		}

		cout << "\tiMaxCnt=" << iMaxCnt;
		vector<int> vctRetData;
		for (auto it : mDataToCnt)
		{
			if (it.second == iMaxCnt)
			{
				vctRetData.push_back(it.first);
			}
		}

		return vctRetData;
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
	TreeNode *root = newNode(3);

	root->right = newNode(4);
	root->left = newNode(2);
	root->left->left = root->left->right = NULL;
	root->right->left = newNode(4);
	root->right->right = newNode(1);
	cout << "\nInput Tree:";
	PrintTree(root);
	cout << "\n";
	Solution objSolution;
	vector<int> vctRet = objSolution.findMode(root);

	// Input: root = [3,9,20,null,null,15,7]
	// Output: [ [3], [9, 20], [15, 7] ]
	cout << "\nOutput: [ ";
	for (auto i : vctRet)
	{
		cout << "[";
		cout << i << ", ";
		cout << "\b\b], ";
	}
	cout << "\b\b ]" << endl;

	return 0;
}

/*
Input Tree:     [2]     [3]     [4]     [4]     [1]
		2       3       4       4       1       iMaxCnt=2
Output: [ [4] ]
*/
