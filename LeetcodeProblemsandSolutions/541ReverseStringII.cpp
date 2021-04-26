/*
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.



Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
	void reverseString(string& s, int iStart, int iEnd)
	{
		if (s.empty())
		{
			return;
		}

		while (iStart < iEnd)
		{
			char chTemp = s[iStart];
			s[iStart] = s[iEnd];
			s[iEnd] = chTemp;
			++iStart;
			--iEnd;
		}
	}

public:

	string reverseStr(string s, int k)
	{
		int iStart = 0;
		int iEnd = s.size() - 1;//1 for array index start with zero
		while (iStart < iEnd)
		{
			int n = min(iEnd, iStart + k - 1);
			//swap substring of size K
			reverseString(s, iStart, n);
			iStart = n;
			while (iStart < n + k + 1)
			{
				++iStart;
			}
		}

		return s;
	}
};

int main()
{
	vector<string> vctInput1 = { "abcdefg", "abcd"};
	vector<int> vctInput2 = { 2, 2};
	string strRet = "";

	Solution objSolution;

	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << "Input: \"" << vctInput1[i].c_str() << "\"" << endl << "Input2 \"" << vctInput2[i] << endl;
		strRet = objSolution.reverseStr(vctInput1[i], vctInput2[i]);
		cout << "Output: \"" << strRet.c_str() << "\"" << endl << endl;
	}

	return 0;
}
/*
Input: "abcdefg"
Input2 "2
Output: "bacdfeg"

Input: "abcd"
Input2 "2
Output: "bacd"

*/
