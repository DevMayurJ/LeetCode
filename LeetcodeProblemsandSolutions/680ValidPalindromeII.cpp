/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
	Output : true
	Example 2 :

	Input : s = "abca"
	Output : true
	Explanation : You could delete the character 'c'.
	Example 3 :

	Input : s = "abc"
	Output : false
	*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
	bool validPalindrome(string s)
	{
		/*
	If they are Same - then just check inside and keep going till you reach the center(left==right)(if odd string) or left>right (if even string)
	If they are NOT same : You now have 2 options
	2.1) Remove Left Element and Check for the Rest of String OR
	2.2) Remove Right Element and Check for the Rest of the string.
	If either of them dont give palindrome then its not a palindorme.
	*/
		int iRight = s.size() - 1;
		int iLeft = 0;
		while (iLeft <= iRight)
		{
			if (s[iLeft] != s[iRight])
			{
				//SKIP left one char and check
				int iLeftNew = iLeft + 1;
				int iRightNew = iRight;
				while (iLeftNew <= iRightNew)
				{
					if (s[iLeftNew] != s[iRightNew])
					{
						break;
					}

					++iLeftNew;
					--iRightNew;
				}

				if (iLeftNew >= iRightNew)
				{
					return true;
				}

				iLeftNew = iLeft;
				iRightNew = iRight - 1;
				while (iLeftNew <= iRightNew)
				{
					if (s[iLeftNew] != s[iRightNew])
					{
						break;
					}

					++iLeftNew;
					--iRightNew;
				}

				if (iLeftNew >= iRightNew)
				{
					return true;
				}

				return false;
			}

			++iLeft;
			--iRight;
		}

		return true;
	}
};

int main()
{
	vector<string> vctInput =
	{	"aba",
		"abca",
		"abc"
	};

	Solution objSolution;

	for (string inp : vctInput)
	{
		cout << "Input = \"" << inp << "\"" << endl;
		bool boRet = objSolution.validPalindrome(inp);
		cout << "Output = \"" << boRet << "\"" << endl << endl;
	}

	return 0;
}

/*
Input = "aba"
Output = "1"

Input = "abca"
Output = "1"

Input = "abc"
Output = "0"
*/
