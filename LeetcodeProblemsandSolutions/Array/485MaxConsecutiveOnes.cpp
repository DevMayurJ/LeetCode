/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Input: nums = [1,0,1,1,0,1]
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int iCnt = 0;
        int iMaxCnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                ++iCnt;
            }
            else
            {
                iCnt = 0;
            }

            iMaxCnt = max(iCnt, iMaxCnt);
        }

        return iMaxCnt;
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
							{1,1,0,1,1,1},
                            {1,0,1,1,0,1}
	};

	int	iMaxOneCnt;
	Solution objSolution;

	for (int i = 0; i < vctInput.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput[i]);
		cout << "\b\b]" << endl;

        iMaxOneCnt = objSolution.findMaxConsecutiveOnes(vctInput[i]);
		cout << "Output:  iMaxOneCnt=" << iMaxOneCnt;
	}

	return 0;
}

/*
Input: [ 1, 1, 0, 1, 1, 1]
Output:  iMaxOneCnt=3
Input: [ 1, 0, 1, 1, 0, 1]
Output:  iMaxOneCnt=2
*/