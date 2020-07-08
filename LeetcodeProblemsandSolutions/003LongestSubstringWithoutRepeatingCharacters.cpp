// LeetTry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	int iRet = 0;
	int iStart = 0;
	int iEnd = 0;
	int n = s.size();
	std::set <char> stData;
	cout << "\nInput:========" << s.c_str();
	while (iStart < n && iEnd < n)
	{
		if (stData.end() == stData.find(s.at(iEnd)))
		{
			stData.insert(s.at(iEnd));
			iEnd++;
			if (iRet < iEnd - iStart)
			{
				iRet = iEnd - iStart;
			}
		}
		else
		{
			stData.erase(s.at(iStart));
			iStart++;
		}

		cout << "\nstData contents:------------------";
		for (auto it : stData)
		{
			cout << it << "\t";
		}

		cout << iRet;
	}

	return iRet;
}

int main()
{
	std::vector<string> vctInput =
	{
		"aab",
		"abcabcbb",
		"pwwkew",
		"bbbbb"
	};

	for (auto it : vctInput)
	{
		int iRet = lengthOfLongestSubstring(it);
		cout << endl << "OutPut: " << iRet << endl;

	}
}

/*
Input:========aab
stData contents:------------------a     1
stData contents:------------------1
stData contents:------------------a     1
stData contents:------------------a     b       2
OutPut: 2

Input:========abcabcbb
stData contents:------------------a     1
stData contents:------------------a     b       2
stData contents:------------------a     b       c       3
stData contents:------------------b     c       3
stData contents:------------------a     b       c       3
stData contents:------------------a     c       3
stData contents:------------------a     b       c       3
stData contents:------------------a     b       3
stData contents:------------------a     b       c       3
stData contents:------------------b     c       3
stData contents:------------------c     3
stData contents:------------------b     c       3
stData contents:------------------b     3
stData contents:------------------3
stData contents:------------------b     3
OutPut: 3

Input:========pwwkew
stData contents:------------------p     1
stData contents:------------------p     w       2
stData contents:------------------w     2
stData contents:------------------2
stData contents:------------------w     2
stData contents:------------------k     w       2
stData contents:------------------e     k       w       3
stData contents:------------------e     k       3
stData contents:------------------e     k       w       3
OutPut: 3

Input:========bbbbb
stData contents:------------------b     1
stData contents:------------------1
stData contents:------------------b     1
stData contents:------------------1
stData contents:------------------b     1
stData contents:------------------1
stData contents:------------------b     1
stData contents:------------------1
stData contents:------------------b     1
OutPut: 1
*/