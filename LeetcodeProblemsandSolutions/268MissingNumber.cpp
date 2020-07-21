#include <iostream>
#include <vector>
using namespace std;

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
*/
class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		int len = nums.size();
		int iSum = len * (len + 1) / 2;
		for (int i = 0; i < len; ++i)
		{
			iSum -= nums[i];
		}

		return iSum;
	}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{3,0,1},
		{9,6,4,2,3,5,7,0,1}
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: ";
		for (auto no : it)
		{
			cout << "\t" << no;
		}

		int iRet = objSolution.missingNumber(it);
		cout << endl << "Output: " << iRet << endl;
	}
}


/*
Input:  3       0       1
Output: 2

Input:  9       6       4       2       3       5       7       0       1
Output: 8
*/
