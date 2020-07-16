#include <iostream>
#include <vector>
using namespace std;

/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
*/

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		if (nums.empty())
		{
			return 0;
		}

		int iRet = -1;
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] != val)
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

		int iRet = objSolution.removeElement(it, 2);
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
Output: 2       Array is: 1     1

Input: 0        0       1       1       1       2       2       3       3       4
Output: 8       Array is: 0     0       1       1       1       3       3       4
*/
