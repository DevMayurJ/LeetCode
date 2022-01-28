#include <iostream>
#include <vector>
#include <queue>
//#include <pair>
using namespace std;

//Definition for a binary tree node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution
{
private:
	vector<vector<int>> vctResult;  // Final vector of all levels data
	vector<int> vctTemp;            // To store the current level data

public:
	vector<vector<int>> levelOrder(Node* root)
	{
		vector<vector<int>> vctRet;
		if (root == NULL)
		{
			return vctRet;
		}

		queue<pair<Node *, int>> q;
		q.push(make_pair(root, 1));

		vector<int> vctCurrLevel;
		int iCurrLevel = 1;
		while (!q.empty())
		{
			pair<Node *, int> node = q.front();
			q.pop();
			for (int i = 0; i < node.first->children.size(); ++i)
			{
				q.push(make_pair(node.first->children[i], node.second + 1));
			}

			if (iCurrLevel == node.second)
			{
				vctCurrLevel.push_back(node.first->val);
			}
			else
			{
				vctRet.push_back(vctCurrLevel);
				vctCurrLevel.clear();
				vctCurrLevel.push_back(node.first->val);
				iCurrLevel++;
			}
		}

		vctRet.push_back(vctCurrLevel);
		return vctRet;
	}
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->val = data;
	return node;
}

int main()
{
	Node *root = newNode(1);
	vector<int> childVal = { 3,2,4 };
	for (int i = 0; i < 3; ++i)
	{
		Node *temp = newNode(childVal[i]);
		root->children.push_back(temp);
	}


	Solution objSolution;
	vector<vector<int>> vctRet = objSolution.levelOrder(root);

	cout << "Output: [ ";
	for (auto vct : vctRet)
	{
		cout << "[";
		for (auto i : vct)
		{
			cout << i << ", ";
		}
		cout << "\b\b], ";
	}
	cout << "\b\b ]" << endl;

	return 0;
}

/*
	Output: [ [1], [3, 2, 4] ]
*/
