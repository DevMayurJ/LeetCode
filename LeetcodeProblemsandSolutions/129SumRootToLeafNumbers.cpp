#include <iostream>
#include <vector>

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

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = new struct TreeNode;
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

class Solution 
{
    private:
        int iAllPathSum = 0;
        
		void TraverseAndSum(TreeNode* root, int iNum)
		{
		    if(root == NULL){
		        return;
		    }
		    
		    iNum = iNum * 10;
		    iNum = iNum + root->val;
		    
		    if(root->left == NULL && root->right == NULL){
		        iAllPathSum += iNum;
		        return;
		    }
		    
		    TraverseAndSum(root->left, iNum);
		    TraverseAndSum(root->right, iNum);
		}
		
	public:
	    int sumNumbers(TreeNode* root) 
	    {
	        TraverseAndSum(root, 0);
	        return iAllPathSum;
	    }
};

int main()
{
	TreeNode *root = newNode(4);

	root->left = newNode(9);
	root->right = newNode(0);
	root->left->left = newNode(5);
	root->left->right = newNode(1);

	Solution objSolution;
	
	int iSum = objSolution.sumNumbers(root);
	
	cout<<"Input: [4,9,0,5,1]\n";	
	cout<<"Output: "<<iSum<<endl;
	
	return 0;
}
