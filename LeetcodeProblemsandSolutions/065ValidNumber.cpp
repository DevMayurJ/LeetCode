#include <iostream>
#include <vector>
using namespace std;

/*
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
At least one digit, followed by a dot '.'.
At least one digit, followed by a dot '.', followed by at least one digit.
A dot '.', followed by at least one digit.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
At least one digit.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.
Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false
Example 4:

Input: s = ".1"
Output: true
*/

class Solution {
public:

	bool isNumber(string s)
	{
		int i = 0;
		int n = s.size();
		//skip the leading whitespaces;
		for (; i < n && isspace(s[i]); ++i);

		//simply skip the leading sign
		if (i < n && s[i] == '+' || s[i] == '-')
		{
			++i;
		}

		//count the number of digits and the number of points.
		int iDigitCnt = 0;
		int iPointCnt = 0;
		for (; i < n; ++i)
		{
			if (isdigit(s[i]))
				++iDigitCnt;
			else if (s[i] == '.')
				++iPointCnt;
			else
				break;
		}

		// check for no more than one point and at least one digit.
		if (iPointCnt > 1 || iDigitCnt < 1)
		{
			return false;
		}

		// check if the significand is followed by 'e'
		if (i < n - 1 && (s[i] == 'e' || s[i] == 'E'))
		{
			++i;
			if (s[i] == '+' || s[i] == '-')
			{
				i++;
			}

			iDigitCnt = 0;
			for (; i < n && isdigit(s[i]); ++i)
			{
				++iDigitCnt;
			}

			if (!iDigitCnt)
			{
				return false;
			}

		}

		//skip the trailing whitespaces
		for (; i < n && isspace(s[i]); ++i);

		return i == n;
	}
};


int main()
{
	std::vector<string> vctInput =
	{
		"0",
		"e",
		".",
		".1",
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		bool boRet = objSolution.isNumber(it);
		cout << endl << "Output: " << boRet << endl;
	}
}

/*

Input: 0

Output: 1

Input: e

Output: 0

Input: .

Output: 0

Input: .1

Output: 1
*/
