/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool containsDuplicate_extramem(vector<int>& nums)
	{
		unordered_set<int> stNums;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (stNums.end() != stNums.find(nums[i]))
			{
				return true;
			}

			stNums.insert(nums[i]);
		}

		return false;
	}

	bool containsDuplicate(vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i - 1] == nums[i])
			{
				return true;
			}

		}

		return false;
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
						{1,2,3,1},
						{1,2,3,4},
						{1,1,1,3,3,4,3,2,4,2},
	};

	bool boRet;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput[i]);
		cout << "\b\b]" << endl;

		boRet = objSolution.containsDuplicate_extramem(vctInput[i]);
		cout << "Output: [ ";
		cout << boRet << "]" << endl;

		boRet = objSolution.containsDuplicate_extramem(vctInput[i]);
		cout << "Output_ExtraMemory: [ ";
		cout << boRet << "]" << endl;
	}

	return 0;
}

/*

Input: [ 1, 2, 3, 1]
Output: [ 1]
Output_ExtraMemory: [ 1]

Input: [ 1, 2, 3, 4]
Output: [ 0]
Output_ExtraMemory: [ 0]

Input: [ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
Output: [ 1]
Output_ExtraMemory: [ 1]
*/
