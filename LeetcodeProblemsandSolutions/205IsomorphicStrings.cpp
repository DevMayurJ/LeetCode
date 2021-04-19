/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/


#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t)
	{
		int i = 0;
		int m = s.size();
		int n = t.size();
		if (m != n)
		{
			return false;
		}

		unordered_map<char, char> stot;
		unordered_map<char, char> ttos;
		for (; i < n; ++i)
		{
			if (stot.end() == stot.find(s[i]) && ttos.end() == ttos.find(t[i]))
			{
				stot[s[i]] = t[i];
				ttos[t[i]] = s[i];
			}
			else if (stot[s[i]] != t[i] || s[i] != ttos[t[i]])
			{
				return false;
			}
		}

		return i == n;
	}
};
int main()
{
	vector<string> vctInpString1 = {
					"egg",
					"foo",
					"paper",
	};
	vector<string> vctInpString2 = {
					"add",
					"bar",
					"title",
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: Input1 = \"" << vctInpString1[i] << "\"" << " Input2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.isIsomorphic(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: Input1 = "egg" Input2 = "add"
Output: 1
Input: Input1 = "foo" Input2 = "bar"
Output: 0
Input: Input1 = "paper" Input2 = "title"
Output: 1
*/
