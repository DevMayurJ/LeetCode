#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
Example 4:

Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
*/

class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s)
	{
		//array of characters a-z which stores first index.
		vector<int> vctChars(26, -1);
		int iMax = -1;
		for (int i = 0; i < s.size(); ++i)
		{
			int iIndex = (s[i] - 'a');
			if (-1 == vctChars[iIndex])
			{
				//first occurence of character found so update index array
				vctChars[iIndex] = i;
			}
			else if (iMax < (i - vctChars[iIndex] - 1))
			{
				//charcter repeated so calculate length 
				iMax = i - vctChars[iIndex] - 1;
			}
		}

		return iMax;
	}
};

int main()
{
	std::vector<string> vctInput =
	{
		"aa",
		"abca",
		"cbzxy",
		"cabbac",
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		int iRet = objSolution.maxLengthBetweenEqualCharacters(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: aa

Output: 0

Input: abca

Output: 2

Input: cbzxy

Output: -1

Input: cabbac

Output: 4
*/
