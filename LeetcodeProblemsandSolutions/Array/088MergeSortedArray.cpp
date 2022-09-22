/*
iven two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = m - 1;
		int j = n - 1;
		int iCombineRight = n + m - 1;

		while (j >= 0)
		{
			if (i >= 0 && nums1[i] > nums2[j])
			{
				nums1[iCombineRight] = nums1[i];
				--i;
			}
			else
			{
				nums1[iCombineRight] = nums2[j];
				--j;
			}

			--iCombineRight;
		}
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
							{1,2,3,0,0,0},
							{1}
	};

	vector<vector<int>> vctInput2 = {
						{2,5,6},
						{}
	};


	vector<int>	vctOutput;
	Solution objSolution;

	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << endl << "Input1: [ ";
		printArray(vctInput1[i]);
		cout << "\b\b]" << endl;

		cout << endl << "Input2: [ ";
		printArray(vctInput2[i]);
		cout << "\b\b]" << endl;

		objSolution.merge(vctInput1[i], vctInput1[i].size(), vctInput2[i], vctInput2[i].size());
		cout << "Output: [ ";
		printArray(vctInput1[i]);
		cout << "\b\b]" << endl;
	}

	return 0;
}

/*

Input1: [ 1, 2, 3, 0, 0, 0]

Input2: [ 2, 5, 6]
Output: [ 1, 2, 3, 0, 0, 0]

Input1: [ 1]

Input2: ]
Output: [ 1]

*/
