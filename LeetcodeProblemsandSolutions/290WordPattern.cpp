/*

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
*/


#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s)
	{
		int j = 0;
		int n = pattern.size();
		unordered_map<char, string> PatternToString;
		unordered_map<string, char> StringToPattern;
		int i = 0;
		for (i = 0; i < n && j < s.size(); ++i)
		{
			string strTemp;
			while (s[j] != '\0' && s[j] != ' ')
			{
				strTemp.push_back(s[j]);
				++j;
			}

			++j;

			if (PatternToString.end() == PatternToString.find(pattern[i]) &&
				StringToPattern.end() == StringToPattern.find(strTemp))
			{
				PatternToString[pattern[i]] = strTemp;
				StringToPattern[strTemp] = pattern[i];
			}
			else if (PatternToString[pattern[i]] != strTemp || StringToPattern[strTemp] != pattern[i])
			{
				return false;
			}
		}

		return i == n && j >= s.size();
	}
};
int main()
{
	vector<string> vctInpString1 = {
					"abba",
					"abba",
					"aaaa",
					"abba"
	};
	vector<string> vctInpString2 = {
					"dog cat cat dog",
					"dog cat cat fish",
					"dog cat cat dog",
					"dog dog dog dog"
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: Input1 = \"" << vctInpString1[i] << "\"" << " Input2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.wordPattern(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: Input1 = "abba" Input2 = "dog cat cat dog"
Output: 1
Input: Input1 = "abba" Input2 = "dog cat cat fish"
Output: 0
Input: Input1 = "aaaa" Input2 = "dog cat cat dog"
Output: 0
Input: Input1 = "abba" Input2 = "dog dog dog dog"
Output: 0
*/
