#include <iostream>
#include <vector>
using namespace std; 

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.
*/

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		if (s.empty())
		{
			return 0;
		}

		int iLen = 0;
		int n = s.size() - 1;
		while (n >= 0 && s[n] == ' ')
		{
			n--;
		}

		while (n >= 0 && s[n] != ' ')
		{
			n--;
			++iLen;
		}

		return iLen;
	}

	//Best Solution for Time
	//	for (int i = s.size() - 1; i >= 0; i--) {
	//		if (s[i] != ' ') ans++;
	//		else if (s[i] == ' ' && ans > 0) return ans;
	//	}
	//	return ans;
	//}

};

int main()
{
	std::vector<string> vctInput =
	{
		"Hello World",
		" ",//MCMXCIV
		"a ",
		"ab    ",
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		int iRet = objSolution.lengthOfLastWord(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input: Hello World

Output: 5

Input:

Output: 0

Input: a

Output: 1

Input: ab

Output: 2
*/
