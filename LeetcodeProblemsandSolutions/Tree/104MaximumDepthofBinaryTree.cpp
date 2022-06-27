#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *      3
 *     / \
 *    9  20
 *   /    \
 *  15     7
 * return its depth = 3.
 *
 */

/*
	Definition for a binary tree node.
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

class Solution 
{
public:
	int maxDepth(TreeNode* root)
	{
		if (NULL == root)
		{
			return 0;
		}

		int iLeft = maxDepth(root->left);
		int iRight = maxDepth(root->right);
		return std::max(iLeft, iRight) + 1;
	}
	
	int maxDepth(TreeNode* root)
        {
                if (NULL == root)
                {
                        return 0;
                }

                queue<TreeNode *> q;
                int iLevel = 0;
                q.push(root);
                while (!q.empty())
                {
                        int iCurrLevelNode = q.size();
                        for (int i = 0; i < iCurrLevelNode; ++i)
                        {
                                TreeNode *currNode = q.front();
                                q.pop();
                                if (currNode->left)
                                        q.push(currNode->left);
                                if (currNode->right)
                                        q.push(currNode->right);
                        }

                        ++iLevel;
                }

                return iLevel;
        }

};

int main()
{
	TreeNode *root = newNode(3);

	root->left = newNode(9);
	root->right = newNode(20);
	root->left->left = newNode(15);

	root->right->right = newNode(7);

	Solution objSolution;
	cout << "Height/MAXDepth of tree is " << objSolution.maxDepth(root);
	return 0;
}

/*
Height/MAXDepth of tree is 3
*/
