/*
You are given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.



Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
Example 2:

Input: s = "Hello"
Output: 1
Example 3:

Input: s = "love live! mu'sic forever"
Output: 4
Example 4:

Input: s = ""
Output: 0
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countSegments_MJ(string s)
	{
		int n = s.size();
		if (n <= 0)
		{
			return 0;
		}

		int iRet = 0;
		int i = 0;
		bool boCharFound = false;
		while (i < n)
		{
			if (s[i] == ' ')
			{
				if (true == boCharFound)
				{
					++iRet;
				}

				boCharFound = false;
			}
			else
			{
				boCharFound = true;
			}

			++i;
		}

		if (true == boCharFound)
		{
			++iRet;
		}

		return iRet;
	}

	int countSegments(string s)
	{
		int iRet = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				continue;
			}

			while (i < s.size() && s[i] != ' ')
			{
				//SKIPP all non -space chars
				i++;
			}

			iRet++;
		}

		return iRet;
	}
};

int main()
{
	vector<string> vctInput =
	{ "Hello, my name is John",
		"Hello",
		"        ",
		"love live! mu'sic forever",
		""
	};

	Solution objSolution;

	for (string inp : vctInput)
	{
		cout << "Input = \"" << inp << "\"" << endl;
		int iRet = objSolution.countSegments_MJ(inp);
		cout << "Output1 = \"" << iRet << "\"" << endl << endl;
		iRet = objSolution.countSegments(inp);
		cout << "Output2 = \"" << iRet << "\"" << endl << endl;
	}

	return 0;
}

/*
Input = "Hello, my name is John"
Output1 = "5"

Output2 = "5"

Input = "Hello"
Output1 = "1"

Output2 = "1"

Input = "        "
Output1 = "0"

Output2 = "0"

Input = "love live! mu'sic forever"
Output1 = "4"

Output2 = "4"

Input = ""
Output1 = "0"

Output2 = "0"
*/
