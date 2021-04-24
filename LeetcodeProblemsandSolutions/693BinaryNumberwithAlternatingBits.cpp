/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n)
	{
		//For decimal we use %10 to get last digit
		//here for binary we use %2 to get last bit

		int prev = n % 2;

		//For decimal we use 10 to remove last digit
		//here for binary we use 2 to remove last bit
		n = n / 2;
		while (n > 0)
		{
			int curr = n % 2;
			if (prev == curr)
			{
				return false;
			}

			prev = curr;
			n = n / 2;
		}

		return true;
	}
	
	bool hasAlternatingBits_SD(int iNum) 
	{
		unsigned int iMask = 0x00000001;
		int iCurr = 0, iPrev = -1;

		while(iNum > 0)
		{ 
			// Check if current bit is ON or OFF
			if(((iNum & iMask) == iMask))
			{
				iCurr = 1;
			}
			else 
			{
				iCurr = 0;
			}

			if(iCurr == iPrev)
			{
				break;
			}

			iPrev = iCurr;
			// So that we don't check all 32 bits when not needed
			iNum = iNum >> 1;	// Same as iNum = iNum / 2;
		}
		if(iNum > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	vector<unsigned int> vctInput = { 5, 11, 2, 16, 12, 7, 9, 3, 256 };
	bool boRet = 0;
	Solution objSolution;

	for (auto it : vctInput)
	{
		boRet = objSolution.hasAlternatingBits(it);
		cout << endl << "Input: " << it << endl << "Output MJ: [ " << boRet << " ]" << endl;
		boRet = objSolution.hasAlternatingBits_SD(it);
		cout<< "Output SD: [ " << boRet << " ]" << endl;
	}
	return 0;
}

/*
Input: 5
Output MJ: [ 1 ]
Output SD: [ 1 ]

Input: 11
Output MJ: [ 0 ]
Output SD: [ 0 ]

Input: 2
Output MJ: [ 1 ]
Output SD: [ 1 ]

Input: 16
Output MJ: [ 0 ]
Output SD: [ 0 ]

Input: 12
Output MJ: [ 0 ]
Output SD: [ 0 ]

Input: 7
Output MJ: [ 0 ]
Output SD: [ 0 ]

Input: 9
Output MJ: [ 0 ]
Output SD: [ 0 ]

Input: 3
Output MJ: [ 0 ]
Output SD: [ 0 ]

Input: 256
Output MJ: [ 0 ]
Output SD: [ 0 ]

*/
