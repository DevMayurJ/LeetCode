/*
	Reverse bits of a given 32 bits unsigned intege

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
so return 964176192 which its binary representation is 00111001011110000010100101000000.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t uiRet = 0;
		for (int i = 0; i < 32; ++i)
		{
			uiRet <<= 1;
			if ((n & 1) == 1)
			{
				++uiRet;
			}

			n >>= 1;
		}

		return uiRet;
	}
};


int main()
{
	vector<unsigned int> vctInput = { 11, 2, 15, 12, 7, 9, 3, 37 };
	unsigned int iRet = 0;
	Solution objSolution;

	for (auto it : vctInput)
	{
		iRet = objSolution.reverseBits(it);
		cout << endl << "Input: " << it << endl << "Output SD: [ " << iRet << " ]" << endl;
	}
	return 0;
}

/*
Input: 11
Output SD: [ 3489660928 ]

Input: 2
Output SD: [ 1073741824 ]

Input: 15
Output SD: [ 4026531840 ]

Input: 12
Output SD: [ 805306368 ]

Input: 7
Output SD: [ 3758096384 ]

Input: 9
Output SD: [ 2415919104 ]

Input: 3
Output SD: [ 3221225472 ]

Input: 37
Output SD: [ 2751463424 ]

*/
