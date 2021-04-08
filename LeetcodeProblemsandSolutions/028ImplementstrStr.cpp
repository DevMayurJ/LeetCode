#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		for (int i = 0; i + needle.length() < haystack.length() + 1; ++i)
		{
			if (haystack.substr(i, needle.length()) == needle)
			{
				return i;
			}
		}

		return -1;
	}
};

int main()
{
	std::vector<std::pair<string, string>> vctInput =
	{
		{"Hello World", "ll"},
		{" ", " "},
		{" ", "a"}
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.first.c_str() << " " << it.second.c_str() << endl;
		int iRet = objSolution.strStr(it.first, it.second);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: Hello World ll

Output: 2

Input:

Output: 0

Input:   a

Output: -1
*/
