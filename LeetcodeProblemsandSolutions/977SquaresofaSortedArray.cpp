/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.



Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> vctRet(n);
		int iStart = 0;
		int iEnd = n - 1;
		int iPos = n - 1;
		//since array is sorted we will use two index approch one for -ve and other for +ve
		while (iStart <= iEnd)
		{
			if (abs(nums[iStart]) > abs(nums[iEnd]))
			{
				vctRet[iPos] = nums[iStart] * nums[iStart];
				++iStart;
			}
			else
			{
				vctRet[iPos] = nums[iEnd] * nums[iEnd];
				--iEnd;
			}

			--iPos;
		}

		return vctRet;
	}
};


int main()
{
	Solution objSolution;
	vector<int> vctOutput;
	vector<vector<int>> vctInput = {
						{-4,-1,0,3,10},
						{-7,-3,2,3,11},
	};

	for (auto it : vctInput)
	{
		cout << endl << "Input:  ";
		for (auto no : it)
		{
			cout << no << "\t";
		}

		vctOutput = objSolution.sortedSquares(it);
		cout << endl << "Output: ";
		for (auto outIt : vctOutput)
		{
			cout << outIt << "\t";
		}
		cout << endl;
	}

	return 0;
}

/*

Input:  -4      -1      0       3       10
Output: 0       1       9       16      100

Input:  -7      -3      2       3       11
Output: 4       9       9       49      121
*/
