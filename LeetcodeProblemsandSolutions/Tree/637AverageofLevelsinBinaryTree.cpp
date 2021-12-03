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
	vector<double> averageOfLevels(TreeNode* root)
	{
		vector<double> vctRet;
		if (NULL == root)
		{
			return vctRet;
		}

		queue<pair<TreeNode *, int>> q;
		q.push(make_pair(root, 1));

		int iCurrLevel = 1;
		vector<double> vctLevelData;
		while (!q.empty())
		{
			pair<TreeNode *, int> node = q.front();
			q.pop();

			if (node.first->left)
			{
				q.push(make_pair(node.first->left, node.second + 1));
			}

			if (node.first->right)
			{
				q.push(make_pair(node.first->right, node.second + 1));
			}

			if (iCurrLevel != node.second)
			{
				double sum = 0;
				for (int val : vctLevelData)
				{
					sum = sum + val;
				}

				vctRet.push_back(sum / vctLevelData.size());
				vctLevelData.clear();
				++iCurrLevel;
			}

			vctLevelData.push_back(node.first->val);
		}

		double sum = 0;
		for (int val : vctLevelData)
		{
			sum = sum + val;
		}

		vctRet.push_back(sum / vctLevelData.size());
		return vctRet;
	}

	vector<double> averageOfLevels_optimum(TreeNode* root) {
		queue<TreeNode*> q;
		vector<double> res;
		double temp;
		int size, i;
		TreeNode* curr;

		q.push(root);

		while (!q.empty()) {
			temp = 0;
			size = q.size();

			for (i = 0; i < size; i++) {

				curr = q.front();
				q.pop();

				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);

				temp += curr->val;
			}

			res.push_back((double)temp / size);
		}

		return res;
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

	root->right = newNode(20);
	root->left = newNode(9);
	root->left->left = root->left->right = NULL;
	root->right->left = newNode(15);
	root->right->right = newNode(7);

	Solution objSolution;
	vector<double> vctRet = objSolution.averageOfLevels(root);

	// Input: root = [3,9,20,null,null,15,7]
	cout << "\nOutput:";
	for (auto avg : vctRet)
	{
		cout << "[";
		cout << avg << "]";
	}

	return 0;
}

