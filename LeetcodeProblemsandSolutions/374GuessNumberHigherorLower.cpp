/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).
Return the number that I picked.



Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1
Example 4:

Input: n = 2, pick = 2
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
	int m_pick;
	/**
	 * Forward declaration of guess API.
	 * @param  num   your guess
	 * @return 	     -1 if num is lower than the guess number
	 *			      1 if num is higher than the guess number
	 *               otherwise return 0
	 * int guess(int num);
	 */
	int guess(int pick)
	{
		if (pick < m_pick)
		{
			return 1;
		}
		else if (pick > m_pick)
		{
			return -1;
		}

		return 0;
	}

public:
	void SetGuess(int pick)
	{
		m_pick = pick;
	}

	int guessNumber(int n)
	{
		int iLeft = 0;
		int iRight = n;
		while (iLeft < iRight)
		{
			//int iMid = (iLeft + iRight)/2;// singed int range crosss
			int iMid = iLeft + (iRight - iLeft) / 2;// singed int range does not crosss
			if (guess(iMid) == -1)
			{
				iRight = iMid;
			}
			else if (guess(iMid) == 1)
			{
				iLeft = iMid + 1;
			}
			else
			{
				return iMid;
			}
		}

		if (iLeft == iRight && !guess(iLeft))
		{
			return iLeft;
		}

		return -1;
	}
};

int main()
{
	vector<int> vctInput = {
						10,
						1,
						2,
						2
	};

	vector<int> vctGuess = {
					6,
					1,
					1,
					2
	};

	Solution objSolution;
	for (int i = 0; i < vctInput.size(); ++i)
	{
		objSolution.SetGuess(vctGuess[i]);
		cout << endl << "Input array = [" << vctInput[i] << "]";
		cout << "\b]" << endl;
		int iRet = objSolution.guessNumber(vctInput[i]);
		cout << "Output= [" << iRet << "]" << endl;
	}
	return 0;
}

/*

Input array = [10]
Output= [6]

Input array = [1]
Output= [1]

Input array = [2]
Output= [1]

Input array = [2]
Output= [2]
*/
