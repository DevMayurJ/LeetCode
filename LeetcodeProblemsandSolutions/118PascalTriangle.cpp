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
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> vctRet;
		if (0 == numRows)
		{
			return vctRet;
		}

		vector<int> vctFirstRow = { 1 };
		vctRet.push_back(vctFirstRow);
		for (int i = 1; i < numRows; ++i)
		{
			vector<int> vctPevRow = vctRet[i - 1];
			vector<int> vctCurrRow = { 1 };
			for (int j = 1; j < i; ++j)
			{
				vctCurrRow.push_back(vctPevRow[j - 1] + vctPevRow[j]);
			}

			vctCurrRow.push_back(1);
			vctRet.push_back(vctCurrRow);
		}

		return vctRet;
	}
};

void printDoubleArray(vector<vector<int>> vctArr)
{
	for (auto itOut : vctArr)
	{
		for (auto it : itOut)
		{
			cout << it << ", ";
		}
	}
}

int main()
{
	vector<int> vctInput = {
							{5},
							{1},
	};


	vector<vector<int>>	vctOutput;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ " << vctInput[i] << "\b\b]" << endl;

		vctOutput = objSolution.generate(vctInput[i]);
		cout << "Output: [ ";
		printDoubleArray(vctOutput);
		cout << "\b\b]" << endl;
	}

	return 0;
}

/*
Input: [ 2, 7, 11, 15]
Output: [ 1, 2]
Output_Optimum: [ 1, 2]

Input: [ 2, 3, 4]
Output: [ 1, 3]
Output_Optimum: [ 1, 3]

Input: [ -1, 0]
Output: [ 1, 2]
Output_Optimum: [ 1, 2]
*/
