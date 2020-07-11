#include <iostream>
#include <vector>
using namespace std; 

/*Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.
*/

class Solution
{
public:
	int myAtoi(string str)
	{
		bool IsNegative = false;
		if (str.size() < 1)
		{
			return 0;
		}

		unsigned int i = 0;
		while (i < str.size())
		{
			if (' ' == str[i])
			{
				++i;
				continue;
			}

			break;
		}

		if (i < str.size())
		{
			if (str[i] == '-')
			{
				IsNegative = true;
				++i;
			}
			else if (str[i] == '+')
			{
				++i;
			}
		}

		double dNo = 0;
		while (i < str.size())
		{
			if ('0' <= str[i] && '9' >= str[i])
			{
				dNo = 10 * dNo + (str[i] - '0');
				++i;
				continue;
			}

			break;
		}

		if (IsNegative)
		{
			dNo = -dNo;
		}

		if (dNo > INT_MAX)
		{
			return INT_MAX;
		}

		if (dNo < INT_MIN)
		{
			return INT_MIN;
		}

		return (int)dNo;
	}
};

int main()
{
	std::vector<string> vctInput =
	{
		"42",
		"123",
		"-123",
		"1534236469",
		"-91283472332",
		"-2147483648" //INT_MIN Value
		//-2147483648
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		int iRet = objSolution.myAtoi(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: 42

Output: 42

Input: 123

Output: 123

Input: -123

Output: -123

Input: 1534236469

Output: 1534236469

Input: -91283472332

Output: -2147483648

Input: -2147483648

Output: -2147483648
*/
