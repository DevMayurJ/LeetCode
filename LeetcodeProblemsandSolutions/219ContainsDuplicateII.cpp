/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array
such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map<int, int> mapNums;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = mapNums.find(nums[i]);
			if (mapNums.end() != it && i - it->second <= k)
			{
				return true;
			}

			mapNums[nums[i]] = i;
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
						{1,0,1,1},
						{1,2,3,1,2,3},
	};

	vector<int> vctInput2 = {
						{3},
						{1},
						{2}
	};

	bool boRet;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput[i]);
		cout << "\b\b]" << endl;

		boRet = objSolution.containsNearbyDuplicate(vctInput[i], vctInput2[i]);
		cout << "Output: [ ";
		cout << boRet << "]" << endl;
	}

	return 0;
}

/*

Input: [ 1, 2, 3, 1]
Output: [ 1]

Input: [ 1, 0, 1, 1]
Output: [ 1]

Input: [ 1, 2, 3, 1, 2, 3]
Output: [ 0]
*/
