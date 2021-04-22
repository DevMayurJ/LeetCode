/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:

Input: "Hello"
Output : "hello"
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string toLowerCase(string str)
	{
		string strRet;
		for (char ch : str)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				strRet.push_back(ch + 32);
			}
			else
			{
				strRet.push_back(ch);
			}
		}

		return strRet;
	}
};

int main()
{
	std::vector<string> vctInput =
	{
		"Hello",
		"here",
		"-LOVELY",
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		string strRet = objSolution.toLowerCase(it);
		cout << endl << "Output: " << strRet .c_str()<< endl;
	}
}

/*
Input: Hello

Output: hello

Input: here

Output: here

Input: -LOVELY

Output: -lovely
*/
