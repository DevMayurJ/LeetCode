/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Input: numRows = 1
Output: [[1]]
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> vctCurrRow = { 1 };
		if (0 == rowIndex)
		{
			return vctCurrRow;
		}

		for (int i = 1; i <= rowIndex; ++i)
		{
			vector<int> vctPevRow = vctCurrRow;
			vctCurrRow.clear();
			vctCurrRow = { 1 };
			for (int j = 1; j < i; ++j)
			{
				vctCurrRow.push_back(vctPevRow[j - 1] + vctPevRow[j]);
			}

			vctCurrRow.push_back(1);
		}

		return vctCurrRow;
	}
};

void printArray(vector<int> vctArr)
{
	cout << "\nOutput: [";
	for (auto itOut : vctArr)
	{
		cout << itOut << ", ";
	}
	cout << "\b]";
}

int main()
{
	vector<int> vctInput = {
							{5},
							{1},
	};


	vector<int>	vctOutput;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ " << vctInput[i] << "]" << endl;

		vctOutput = objSolution.getRow(vctInput[i]);
		printArray(vctOutput);
	}

	return 0;
}

/*
Input: [ 5]

Output: [1, 5, 10, 10, 5, 1,]
Input: [ 1]

Output: [1, 1,]
*/
