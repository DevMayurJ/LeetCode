/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.



Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
*/

#include<iostream>
#include<vector>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
	int m_version;
	bool isBadVersion(int version)
	{
		if (m_version == version)
			return true;
		return false;
	}

public:
	void SetBadVersion(int version)
	{
		m_version = version;
	}

	int firstBadVersion(int n)
	{
		int iLeft = 0;
		int iRight = n;
		while (iLeft < iRight)
		{
			//int iMid = (iLeft + iRight)/2;// singed int range crosss
			int iMid = iLeft + (iRight - iLeft) / 2;// singed int range does not crosss
			if (isBadVersion(iMid))
			{
				iRight = iMid;
			}
			else
			{
				iLeft = iMid + 1;
			}
		}

		if (iLeft == iRight && isBadVersion(iLeft))
		{
			return iLeft;
		}

		return -1;
	}
};

int main()
{
	vector<int> vctInput = {
						5,
						1
	};

	vector<int> vctBadV = {
					4,
					1
	};

	Solution objSolution;
	for (int i = 0; i < vctInput.size(); ++i)
	{
		objSolution.SetBadVersion(vctBadV[i]);
		cout << endl << "Input array = [" << vctInput[i] << "]";
		cout << "\b]" << endl;
		int iRet = objSolution.firstBadVersion(vctInput[i]);
		cout << "Output= [" << iRet << "]" << endl;
	}
	return 0;
}

/*

Input array = [5]
Output= [4]

Input array = [1]
Output= [1]
*/
