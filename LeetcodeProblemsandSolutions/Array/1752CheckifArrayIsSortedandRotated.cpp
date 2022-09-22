/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.



Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
Example 4:

Input: nums = [1,1,1]
Output: true
Explanation: [1,1,1] is the original sorted array.
You can rotate any number of positions to make nums.
Example 5:

Input: nums = [2,1]
Output: true
Explanation: [1,2] is the original sorted array.
You can rotate the array by x = 5 positions to begin on the element of value 2: [2,1].
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	bool check(vector<int>& nums)
	{
		int iSortBreakCnt = 0;
		size_t stSize = nums.size();
		for (size_t i = 0; i < stSize; ++i)
		{
			// we will compare last number with first number for sorting sequence using %size e.g [2,1,3,4]
			if (nums[i] > nums[(i + 1) % stSize])
			{
				iSortBreakCnt++;
			}
		}

		if (1 >= iSortBreakCnt) // If array is rotated the at Max only once sorting sequence broken 
		{
			return true;
		}

		return false;
	}
};

void PrintVector(vector<int> vctInput)
{
	cout << "\n[";
	for (int val : vctInput)
	{
		cout << val << ",";
	}

	cout << "]";
}

int main()
{
	vector<vector<int>> vctInput1 = {
		{3,4,5,1,2},
		{2,1,3,4},
		{1,2,3},
		{1,1,1},
		{2,1}
	};

	Solution objSolution;
	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << "\nInput: num1 = ";
		PrintVector(vctInput1[i]);
		cout << "\nOutput: " << objSolution.check(vctInput1[i]);
	}
}

/*
Input: num1 =
[3,4,5,1,2,]
Output: 1
Input: num1 =
[2,1,3,4,]
Output: 0
Input: num1 =
[1,2,3,]
Output: 1
Input: num1 =
[1,1,1,]
Output: 1
Input: num1 =
[2,1,]
Output: 1
*/

