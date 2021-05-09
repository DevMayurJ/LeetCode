/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool isPalindrome(string str)
	{
		int iLeft = 0;
		int iRight = str.size() - 1;
		while (iLeft <= iRight)
		{
			while (iLeft < iRight && !isalnum(str[iLeft]))
			{
				++iLeft;
			}

			char chLeft = tolower(str[iLeft]);

			while (iRight > iLeft && !isalnum(str[iRight]))
			{
				--iRight;
			}

			char chRight = tolower(str[iRight]);
			if (chRight != chLeft)
			{
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
	{ "A man, a plan, a canal: Panama",
		"race a car",};

	Solution objSolution;

	for (string inp : vctInput)
	{
		cout << "Input = \"" << inp << "\"" << endl;
		bool boRet = objSolution.isPalindrome(inp);
		cout << "Output = \"" << boRet << "\"" << endl << endl;
	}

	return 0;
}

/*
Input = "A man, a plan, a canal: Panama"
Output = "1"

Input = "race a car"
Output = "0"

*/
