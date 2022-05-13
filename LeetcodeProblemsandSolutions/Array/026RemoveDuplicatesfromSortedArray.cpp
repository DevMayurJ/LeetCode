#include <iostream>
#include <vector>
using namespace std; 

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
*/

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())
		{
			return 0;
		}

		int iRet = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[iRet] != nums[i])
			{
				++iRet;
				nums[iRet] = nums[i];
			}
		}

		return iRet + 1;
	}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{1,1,2},
		{0,0,1,1,1,2,2,3,3,4 }
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: ";
		for (auto no : it)
		{
			cout << no << "\t";
		}

		int iRet = objSolution.removeDuplicates(it);
		cout << endl << "Output: " << iRet << "\tArray is: ";
		for (int i = 0; i < iRet; ++i)
		{
			cout << it[i] << "\t";
		}

		cout << endl;
	}
}

/*

Input: 1        1       2
Output: 2       Array is: 1     2

Input: 0        0       1       1       1       2       2       3       3       4
Output: 5       Array is: 0     1       2       3       4
*/
