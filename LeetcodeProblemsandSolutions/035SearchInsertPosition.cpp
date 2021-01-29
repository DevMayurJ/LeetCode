#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		if (nums.empty())
		{
			return 0;
		}

		if (target < nums[0])
		{
			return 0;
		}

		int iRight = nums.size() - 1;
		if (target > nums[iRight])
		{
			return nums.size();
		}

		int iLeft = 0;
		while (iLeft <= iRight)
		{
			int iMid = (iLeft + iRight) / 2;
			if (nums[iMid] == target)
			{
				return iMid;
			}
			else
			{
				if (target < nums[iMid])
				{
					iRight = iMid - 1;
				}
				else
				{
					iLeft = iMid + 1;
				}
			}
		}   //while

		return iLeft;
	}
	
	int searchInsert_1(vector<int>& vctNums, int iTarget) 
	{
		if(vctNums.empty())
	   		return 0;
			
		int iSize = vctNums.size();
		
	    	if (iTarget > vctNums[iSize - 1])
			return vctNums.size();
					
	        int i;
		
	        for(i = 0; i < iSize && vctNums[i] <= iTarget; ++i)
	        {
	            if(vctNums[i] == iTarget)
	                 break;      
	        }
		        
	        return i;
	}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{1,3,5,6}
	};

	//{1, 3, 5, 6 } 2
	//[1] 1
	//[1, 3, 5, 6] 0

	vector<int> vctTest =
	{
		1,
		0,
		7,
		2,
		5
	};

	Solution objSolution;
	for (auto it : vctTest)
	{
		cout << endl << "Input: ";
		for (auto no : vctInput.at(0))
		{
			cout << no << "\t";
		}

		cout << endl << "TestValue: " << it;
		int iRet = objSolution.searchInsert(vctInput.at(0), it);
		int iRet_1 = objSolution.searchInsert_1(vctInput.at(0), it);
		cout << endl << "Output: " << iRet;
		cout << endl << "Output: " << iRet_1;
		cout << endl;
	}
}

/*
Input: 1        3       5       6
TestValue: 1
Output: 0

Input: 1        3       5       6
TestValue: 0
Output: 0

Input: 1        3       5       6
TestValue: 7
Output: 4

Input: 1        3       5       6
TestValue: 2
Output: 1

Input: 1        3       5       6
TestValue: 5
Output: 2
*/
