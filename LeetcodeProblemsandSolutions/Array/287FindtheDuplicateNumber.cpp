/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums)
	{
		//Slow and Fast pointer method or sort and compare two consecative elements
		int iSlow = nums[0];
		int iFast = nums[0];
		do
		{
			iSlow = nums[iSlow];
			iFast = nums[nums[iFast]];
		} while (iSlow != iFast);

		//Fast and Slow pointer colid
		iFast = nums[0];
		while (iSlow != iFast)
		{
			iSlow = nums[iSlow];
			iFast = nums[iFast];
		}

		return iSlow;
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
							{1,3,4,2,2},
							{3,1,3,4,2},
	};


	vector<int>	vctOutput;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput[i]);
		cout << "\b\b]" << endl;

		int iRet = objSolution.findDuplicate(vctInput[i]);
		cout << "Output: [ " << iRet << " ]" << endl;
	}

	return 0;
}

/*
Input: [ 2, 7, 11, 15]
Output: [ 1, 2]
Output_Optimum: [ 1, 2]

Input: [ 2, 3, 4]
Output: [ 1, 3]
Output_Optimum: [ 1, 3]

Input: [ -1, 0]
Output: [ 1, 2]
Output_Optimum: [ 1, 2]
*/
