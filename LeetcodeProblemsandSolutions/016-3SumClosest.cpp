/*
16. 3Sum Closest
Medium

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.


Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& vctNums, int target)
	{
		int n = vctNums.size();
		//sorted array so that we can use binary search 
		sort(vctNums.begin(), vctNums.end());
		int iRet = vctNums[0] + vctNums[1] + vctNums[n - 1];
		for (int i = 0; i < n - 2; ++i)
		{
			int iLeft = i + 1;
			int iRight = n - 1;
			//Get all possible closest sum by considering ith element
			//and other two element by binary search
			while (iLeft < iRight)
			{
				int iCurrSum = vctNums[i] + vctNums[iLeft] + vctNums[iRight];
				if (target > iCurrSum)
				{
					++iLeft;
				}
				else
				{
					--iRight;
				}

				if (abs(target - iCurrSum) < abs(target - iRet))
				{
					//new closest element found
					iRet = iCurrSum;
				}
			}

		}

		return iRet;
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
								{-1,2,1,-4},
	};

	vector<int> vctInput2= {
							1,
	};

	Solution objSolution;
	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput1[i]);
		cout << "\b\b]" << endl;
		cout << "Target=" << vctInput2[i] << endl;
		int iRet = objSolution.threeSumClosest(vctInput1[i], vctInput2[i]);

		cout << "Output: " << iRet << endl;
	}
	return 0;
}

/*
Input: [ -1, 2, 1, -4]
Target=1
Output: 2
*/


