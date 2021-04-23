/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Input: n = 1
Output: true
Explanation: 2^0 = 1

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n)
	{
		if (n <= 0)
		{
			return false;
		}

		//Power of 2 means only one bit of n is '1', so use the trick n&(n-1)==0 to judge whether that is the case
		return !(n & (n - 1));
	}
};

int main()
{
	vector<unsigned int> vctInput = { 11, 2, 16, 12, 7, 9, 3, 256 };
	bool boRet = 0;
	Solution objSolution;

	for (auto it : vctInput)
	{
		boRet = objSolution.isPowerOfTwo(it);
		cout << endl << "Input: " << it << endl << "Output : [ " << boRet << " ]" << endl;
	}
	return 0;
}

/*
Input: 11
Output : [ 0 ]

Input: 2
Output : [ 1 ]

Input: 16
Output : [ 1 ]

Input: 12
Output : [ 0 ]

Input: 7
Output : [ 0 ]

Input: 9
Output : [ 0 ]

Input: 3
Output : [ 0 ]

Input: 256
Output : [ 1 ]
*/
