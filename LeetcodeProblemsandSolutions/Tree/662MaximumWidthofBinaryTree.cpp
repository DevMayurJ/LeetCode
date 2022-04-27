/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end - nodes(the leftmost and rightmost non - null nodes), where the null nodes between the end - nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32 - bit signed integer.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PrintTree(TreeNode* root)
{
    if (NULL == root)
    {
        return;
    }

    TreeNode* curr = root;
    stack<TreeNode*> stData;
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

TreeNode* newNode(int data)
{
    TreeNode* Node = new TreeNode();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}


class Solution {
public:

    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        //queue for level order traversel with node id
        queue <pair<TreeNode*, long long >> qNodeToID;
        qNodeToID.push({ root, 0 });
        int iRet = 0;
        while (!qNodeToID.empty())
        {
            int iLeftMostID = 0;
            int iRightMostID = 0;
            long long iSize = qNodeToID.size();
            long long iCurrMin = qNodeToID.front().second;
            for (int i = 0; i < iSize; ++i)
            {
                long long iCurrID = qNodeToID.front().second - iCurrMin;;
                TreeNode* temp = qNodeToID.front().first;
                qNodeToID.pop();
                if (i == 0)
                {
                    iLeftMostID = iCurrID;
                }

                if (i == iSize - 1)
                {
                    iRightMostID = iCurrID;
                }

                //leftChildID =  2*i+1 and rightChildID=2*i+2
                if (temp->left)
                {
                    qNodeToID.push({
                      temp->left,
                      iCurrID * 2 + 1
                        });
                }
                if (temp->right)
                {
                    qNodeToID.push(
                        { temp->right, (2 * iCurrID) + 2 }
                    );
                }
            }

            iRet = max(iRet, iRightMostID - iLeftMostID + 1);
        }

        return iRet;
    }
};


int main()
{
    TreeNode* root = newNode(3);

    root->left = newNode(9);
    root->right = newNode(20);
    root->left->left = newNode(15);

    root->right->right = newNode(7);
    cout << "Input Binary Tree: ";
    PrintTree(root);
    Solution objSolution;
    cout << "\nOutput: " << objSolution.widthOfBinaryTree(root);
    return 0;
}