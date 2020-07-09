#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		//Negative numbers can not be pallindrome
		//Zero is palindrome number but number ends with zero can not be pallindrome
		if (x < 0 || (x != 0 && x % 10 == 0))
		{
			return false;
		}

		//reverser half of the number
		int iRev = 0;
		while (x > iRev)
		{
			iRev = iRev * 10 + x % 10;
			x = x / 10;
		}

		if (x == iRev || x == iRev / 10)
		{
			return true;
		}

		return false;
	}
};

int main()
{
	std::vector<int> vctInput =
	{
		121,
		-121,
		120,
		1534236469,
		0
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it << endl;
		int iRet = objSolution.isPalindrome(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: 121

Output: 1

Input: -121

Output: 0

Input: 120

Output: 0

Input: 1534236469

Output: 0

Input: 0

Output: 1
*/

