#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

class Solution
{
public:
	bool isValid(string s)
	{
		if (s.empty())
		{
			return true;
		}

		stack<char> stChar;
		for (auto it : s)
		{
			if ('(' == it || '{' == it || '[' == it)
			{
				stChar.push(it);
			}
			else
			{
				if (stChar.empty())
				{
					return false;
				}

				char ch = stChar.top();
				stChar.pop();
				if (it == '}' && ch != '{')
				{
					return false;
				}

				if (it == ')' && ch != '(')
				{
					return false;
				}

				if (it == ']' && ch != '[')
				{
					return false;
				}
			}

		}

		if (!stChar.empty())
		{
			return false;
		}

		return true;
	}
};

int main()
{
	std::vector<string> vctInput =
	{
		"()",
		"()[]{}",
		"([)]",
		"{[]}",
		"]",
		""
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		int iRet = objSolution.isValid(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: ()

Output: 1

Input: ()[]{}

Output: 1

Input: ([)]

Output: 0

Input: {[]}

Output: 1

Input: ]

Output: 0

Input:

Output: 1
*/
