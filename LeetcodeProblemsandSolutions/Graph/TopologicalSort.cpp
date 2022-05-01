#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class Solution
{
public:
	//Function to return list containing vertices in Topological order. 
	void topoSortUtl(int iNode, vector<int> vctAdjList[], vector<int>& vctVisited, stack<int>& stTopo)
	{
		if (!vctVisited[iNode])
		{
			vctVisited[iNode] = 1;
			for (int iCurrNode : vctAdjList[iNode])
			{
				if (!vctVisited[iCurrNode])
				{
					topoSortUtl(iCurrNode, vctAdjList, vctVisited, stTopo);
				}
			}

			stTopo.push(iNode);
		}
	}

	vector<int> topoSort(int nNode, vector<int> vctAdjList[])
	{
		vector<int> vctVisited(nNode, 0);
		stack<int> stTopo;

		for (int i = 0; i < nNode; i++)
		{
			if (vctVisited[i] == 0)
			{
				topoSortUtl(i, vctAdjList, vctVisited, stTopo);
			}
		}

		vector<int> vctTopo;
		while (!stTopo.empty())
		{
			vctTopo.push_back(stTopo.top());
			stTopo.pop();
		}

		return vctTopo;
	}
};


void printArray(vector<int> vctArr)
{
	for (auto it : vctArr)
	{
		cout << it << ", ";
	}
}

void Case1()
{
	int V = 4, E = 3;
	//vector<vector<int>> vctAdj(V, vector<int>(E));
/*
1, 0.
2, 0.
3, 0.

	2
	/\
	 |
	 |
3<---0--->1

// dfs will be 0 1 2 4 3.
*/
	vector<int> vctAdj[4] = {
		{},
		{0},
		{0},
		{0}
	};

	Solution objSolution;
	vector<int> vctTopo = objSolution.topoSort(V, vctAdj);
	cout << endl << "Output Topological Sort: [ ";
	printArray(vctTopo);
	cout << "\b\b]" << endl;
}

int main()
{
	Case1();
}

/*
Output Topological Sort : [3, 2, 1, 0]
*/