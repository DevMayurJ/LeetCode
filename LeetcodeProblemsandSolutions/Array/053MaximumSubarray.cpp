/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.


Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Input: nums = [1]
Output: 1

Input: nums = [5,4,-1,7,8]
Output: 23

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int iCurrSum = 0;
		int iMaxxSum = INT_MIN;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			iCurrSum = iCurrSum + nums[i];
			iMaxxSum = max(iCurrSum, iMaxxSum);
			if (iCurrSum < 0)
			{
				iCurrSum = 0;
			}
		}

		return iMaxxSum;
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
	vector<vector<int>> vctInput = {
						{-2,1,-3,4,-1,2,1,-5,4},
						{1},
						{5,4,-1,7,8}
	};

	int iRet;
	Solution objSolution;

	for (size_t i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput[i]);
		cout << "\b\b]" << endl;

		iRet = objSolution.maxSubArray(vctInput[i]);
		cout << "Output: [ ";
		cout << iRet << "]" << endl;
	}

	return 0;
}

/*

Input: [ -2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: [ 6]

Input: [ 1]
Output: [ 1]

Input: [ 5, 4, -1, 7, 8]
Output: [ 23]
*/