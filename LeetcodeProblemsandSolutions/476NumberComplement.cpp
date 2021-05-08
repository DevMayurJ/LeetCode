/*
Given a positive integer num, output its complement number.The complement strategy is to flip the bits of its binary representation.



Example 1:

Input: num = 5
	Output : 2
	Explanation : The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
	Example 2 :

	Input : num = 1
	Output : 0
	Explanation : The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findComplement(int num)
	{
		unsigned i = 0;
		for (i = 1; i <= num; i <<= 1)
		{
			num ^= i;
		}

		return num;
	}

	int findComplement_1(int num)
	{
		unsigned mask = ~0; //num          = 00000101
		while (num & mask)
		{
			mask <<= 1;
		}

		//mask         = 11111000
		/*
		~mask & ~num = 00000 111
					&  11111 010
					=  00000 010
			   */

		return ~mask & ~num;
	}
};

int main()
{
	vector<int> vctInput = {5, 1, 12, 90 };
	vector<int>	vctOutput;
	Solution objSolution;

	for (auto it : vctInput)
	{
		cout << endl << "Input: [ " << it << "]" << endl;

		int iRet = objSolution.findComplement(it);
		cout << "Output1: [ " << iRet << "]" << endl;
		int iRet1 = objSolution.findComplement_1(it);
		cout << "Output2: [ " << iRet1 << "]" << endl;
	}
}

/*
Input: [ 5]
Output1: [ 2]
Output2: [ 2]

Input: [ 1]
Output1: [ 0]
Output2: [ 0]

Input: [ 12]
Output1: [ 3]
Output2: [ 3]

Input: [ 90]
Output1: [ 37]
Output2: [ 37]
*/