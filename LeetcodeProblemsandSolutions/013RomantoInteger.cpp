#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution
{
public:
	int romanToInt_MJ(string s)
	{
		int iRet = 0;
		if (s.empty())
		{
			return iRet;
		}

		unordered_map<char, int> umRomanInt
		{
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
		};

		size_t stLen = s.size();
		iRet += umRomanInt[s[0]];
		for (unsigned int i = 1; i < stLen; ++i)
		{
			char pev = s[i - 1];
			char curr = s[i];

			if (pev == 'I' && (curr == 'V' || curr == 'X'))
			{
				iRet = iRet + umRomanInt[curr] - 2 * umRomanInt[pev];
			}
			else if (pev == 'X' && (curr == 'L' || curr == 'C'))
			{
				iRet = iRet + umRomanInt[curr] - 2 * umRomanInt[pev];
			}
			else if (pev == 'C' && (curr == 'D' || curr == 'M'))
			{
				cout << "iRet: " << iRet << "\tcurr: " << umRomanInt[curr] << "\tpev: " << umRomanInt[pev] << "\t";
				iRet = iRet + umRomanInt[curr] - 2 * umRomanInt[pev];
			}
			else
			{
				iRet += umRomanInt[s[i]];
			}

			cout << iRet << "\t";
		}

		return iRet;
	}

	int romanToInt(string s)
	{
		int iRet = 0;
		if (s.empty())
		{
			return iRet;
		}

		unordered_map<char, int> umRomanInt
		{
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
		};

		size_t stLen = s.size();
		unsigned int i = 0;
		for (i = 0; i < stLen - 1; ++i)
		{
			if (umRomanInt[s[i]] >= umRomanInt[s[i + 1]])
			{
				iRet += umRomanInt[s[i]];
			}
			else
			{
				iRet -= umRomanInt[s[i]];
			}
		}

		iRet += umRomanInt[s[i]];
		return iRet;
	}
};

int main()
{
	std::vector<string> vctInput =
	{
		"III",
		"MCMXCIV",//1994
		"IV",
		"LVIII"//58,
		"IX"
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		int iRet = objSolution.romanToInt(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: III

Output: 3

Input: MCMXCIV

Output: 1994

Input: IV

Output: 4

Input: LVIIIIX

Output: 67
*/
