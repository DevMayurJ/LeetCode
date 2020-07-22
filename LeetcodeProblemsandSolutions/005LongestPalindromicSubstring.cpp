#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
	void GetMaxPalindrome(string s, int iLeft, int iRight, int &iStart, int &iPalilen)
	{
		iPalilen = 0;
		//Odd size palindromic substring case. e.g bab
		if (iLeft == iRight)
		{
			--iLeft;
			++iRight;
			++iPalilen;
		}

		while (iLeft >= 0 && iRight < s.size() && s[iLeft] == s[iRight])
		{
			iStart = iLeft;
			iPalilen += 2;
			--iLeft;
			++iRight;
		}
	}

	string longestPalindrome(string s)
	{
		int iLen = s.size();
		int iStart = 0;
		int iMaxPaliLen = 0;
		for (int i = 0; i < iLen; ++i)
		{
			int iCurrStart = i;
			int iPalilen = 0;
			//check for odd size
			GetMaxPalindrome(s, i, i, iCurrStart, iPalilen);
			if (iMaxPaliLen < iPalilen)
			{
				iStart = iCurrStart;
				iMaxPaliLen = iPalilen;
			}

			//check for even size
			GetMaxPalindrome(s, i, i + 1, iCurrStart, iPalilen);
			if (iMaxPaliLen < iPalilen)
			{
				iStart = iCurrStart;
				iMaxPaliLen = iPalilen;
			}
		}

		return s.substr(iStart, iMaxPaliLen);
	}
};

int main()
{
	map<string, string> mInputOutput =
	{
		pair<string, string>("babad", "bab"),
		pair<string, string>("cbbd", "bb"),
	};

	Solution objSolution;
	for (auto it : mInputOutput)
	{
		cout << endl << "Input: " << it.first.c_str();
		string strRet = objSolution.longestPalindrome(it.first);
		if (strRet == it.second)
		{
			cout << endl << "Output: " << strRet.c_str() << " PASSED" << endl;
		}
		else
		{
			cout << endl << "Output: " << strRet.c_str() << " FAILED" << endl;
		}
	}
}

/*

Input: babad
Output: bab PASSED

Input: cbbd
Output: bb PASSED

*/
