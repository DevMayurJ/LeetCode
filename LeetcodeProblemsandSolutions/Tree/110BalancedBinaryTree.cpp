/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

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
    int HeightOFBT(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        
        int iLeftHeight = HeightOFBT(root->left);
        if (-1 == iLeftHeight)
        {
            return -1;
        }
        
        int iRightHeight = HeightOFBT(root->right);
        if (-1 == iRightHeight)
        {
            return -1;
        }
        
        if (std::abs(iRightHeight - iLeftHeight) > 1)
        {
            return -1;
        }
        
        return max(iLeftHeight, iRightHeight) + 1;  //1 for root node
    }
    
    bool isBalanced(TreeNode* root) 
    {
        return (-1 != HeightOFBT(root));
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

	root->right->left = newNode(15);
	root->right->right = newNode(7);

	cout << "Input Binary Tree: ";
	PrintTree(root);
	Solution objSolution;
	cout << "\nOutput isBalanced: " << objSolution.isBalanced(root);
	return 0;
}

/*
Input Binary Tree:      [9]     [3]     [15]    [20]    [7]
Output isBalanced: 1
*/