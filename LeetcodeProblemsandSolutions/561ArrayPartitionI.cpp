/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn)
such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.

 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums)
	{
		int iSum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < (nums.size() - 1); i = i + 2)
		{
			iSum += nums[i];
		}

		return iSum;
	}
};

int main()
{
	vector<vector<int>> vctInput = {
						{1,4,3,2},
						{6,2,6,5,1,2},
	};

	Solution objSolution;
	for (auto list : vctInput)
	{
		cout << endl << "Input array = [";
		for (auto l : list)
		{
			cout << l << ",";
		}
		cout << "\b]" << endl;
		int iRet = objSolution.arrayPairSum(list);
		cout << "Output= [" << iRet << "]" << endl;
	}
	return 0;
}

/*
Input array = [1, 4, 3, 2]
Output = [4]

Input array = [6, 2, 6, 5, 1, 2]
Output = [9]
*/
