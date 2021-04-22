/*
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int iLeft = 0;
		int iRight = nums.size() - 1;
		while (iLeft <= iRight)
		{
			int iMid = (iLeft + iRight) / 2;
			if (nums[iMid] == target)
			{
				return iMid;
			}
			else if (nums[iMid] < target)
			{
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid - 1;
			}
		}

		return -1;
	}
};

void printArray(vector<int> vctArr)
{
	for (auto it : vctArr)
	{
		cout << it << ", ";
	}
}

int main()
{
	vector<vector<int>> vctInput1 = {
						{-1,0,3,5,9,12},
						{-1,0,3,5,9,12},
						{5},
	};

	vector<int> vctInput2 = {
					{9},
					{2},
					{5},
	};

	int iRet;
	Solution objSolution;

	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput1[i]);
		cout << "\b\b] target=" << vctInput2[i] << endl;

		iRet = objSolution.search(vctInput1[i], vctInput2[i]);
		cout << "Output: [ ";
		cout << iRet << "]" << endl;
	}

	return 0;
}

/*
Input: [ -1, 0, 3, 5, 9, 12] target=9
Output: [ 4]

Input: [ -1, 0, 3, 5, 9, 12] target=2
Output: [ -1]

Input: [ 5] target=5
Output: [ 0]
*/
