/*
 *	Given an array, replace every element with the greatest number to its right and replace the last element with -1.
 *  Then return the array.
 *
 *  Example: Input: arr = [17,18,5,4,6,1]
 *			 Output: [18,6,6,6,1,-1]
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum_MJ(vector<int>& numbers, int target)
	{
		unordered_map<int, int> data;
		vector<int> vctRet;
		for (int i = 0; i < numbers.size(); ++i)
		{
			int iNo = target - numbers[i];
			auto it = data.find(iNo);
			if (it != data.end())
			{
				vctRet.push_back(it->second + 1);
				vctRet.push_back(i + 1);
				return vctRet;
			}

			data[numbers[i]] = i;
		}

		return vctRet;
	}

	vector<int> twoSum(vector<int>& nums, int target)
	{
		int i = 0, j = nums.size() - 1;
		while (j > i)
		{
			int x = nums[j] + nums[i];
			if (x == target)
			{
				return { i + 1,j + 1 };
			}
			else if (x < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return {};
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
							{2,7,11,15},
							{2,3,4},
							{-1,0},
	};

	vector<int> vctInput2 = { 9, 6, -1};

	vector<int>	vctOutput;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput[i]);
		cout << "\b\b]" << endl;

		vctOutput = objSolution.twoSum_MJ(vctInput[i], vctInput2[i]);
		cout << "Output: [ ";
		printArray(vctOutput);
		cout << "\b\b]" << endl;

		vctOutput = objSolution.twoSum(vctInput[i], vctInput2[i]);
		cout << "Output_Optimum: [ ";
		printArray(vctOutput);
		cout << "\b\b]" << endl;
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
