#include <iostream>
#include <vector>
using namespace std;

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		//a) XOR of a number with itself is 0.
		//b) XOR of a number with 0 is number itself.
		int iLen = nums.size();
		if (iLen <= 0)
		{
			return 0;
		}

		int iRet = nums[0];
		for (int i = 1; i < iLen; ++i)
		{
			iRet = iRet ^ nums[i];
		}

		return iRet;
	}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{2,2,1},
		{4,1,2,1,2}
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: ";
		for (auto no : it)
		{
			cout << "\t" << no << endl;
		}
		
		int iRet = objSolution.singleNumber(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input:  2
		2
		1

Output: 1

Input:  4
		1
		2
		1
		2

Output: 4
*/
