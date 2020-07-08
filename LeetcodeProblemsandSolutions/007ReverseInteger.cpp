#include <iostream>
#include <vector>
using namespace std;

/*
Given a 32-bit signed integer, reverse digits of an integer.
*/

/*
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
Memory Usage: 6 MB, less than 54.58% of C++ online submissions for Reverse Integer.
*/

int reverse(int x)
{
	int iRev = 0;
	while (x != 0)
	{
		int iRem = x % 10;
		if (x > 0 && (iRev > (INT_MAX - iRem) / 10))
		{
			return 0;
		}

		if (x < 0 && (iRev < (INT_MIN - iRem) / 10))
		{
			return 0;
		}

		iRev = iRev * 10 + iRem;
		x /= 10;
	}

	return iRev;
}

int main()
{
	std::vector<int> vctInput =
	{
		123,
		-123,
		120,
		1534236469,
		//-2147483648
	};

	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it << endl;
		int iRet = reverse(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: 123

Output: 321

Input: -123

Output: -321

Input: 120

Output: 21

Input: 1534236469

Output: 0
*/
