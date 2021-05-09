/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".
Example 4:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{

public:
	bool backspaceCompare(string s, string t)
	{
		int n1 = s.size() - 1;
		int n2 = t.size() - 1;
		int iSkp1 = 0;
		int iSkp2 = 0;
		while (n1 >= 0 || n2 >= 0)
		{
			while (n1 >= 0)
			{
				if (s[n1] == '#')
				{
					++iSkp1;
					--n1;
				}
				else if (iSkp1 > 0)
				{
					--iSkp1;
					--n1;
				}
				else
				{
					break;
				}
			}

			while (n2 >= 0)
			{
				if (t[n2] == '#')
				{
					++iSkp2;
					--n2;
				}
				else if (iSkp2 > 0)
				{
					--iSkp2;
					--n2;
				}
				else
				{
					break;
				}
			}

			if (n2 >= 0 && n1 >= 0 && s[n1] != t[n2])
			{
				return false;
			}

			//if (n2 >= 0 && n1 >= 0 && n1 != n2)
			if ((n1 >= 0) != (n2 >= 0))
			{
				return false;
			}

			--n1;
			--n2;
		}

		return true;
	}
};

int main()
{
	vector<string> vctInpString1 = {
					"ab#c",
					"ab##",
					"a##c",
					"a#c"
	};
	vector<string> vctInpString2 = {
					"ad#c",
					"c#d#",
					"#a#c",
					"b"
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: num1 = \"" << vctInpString1[i] << "\"" << " num2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.backspaceCompare(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: num1 = "ab#c" num2 = "ad#c"
Output: 1
Input: num1 = "ab##" num2 = "c#d#"
Output: 1
Input: num1 = "a##c" num2 = "#a#c"
Output: 1
Input: num1 = "a#c" num2 = "b"
Output: 0
*/
