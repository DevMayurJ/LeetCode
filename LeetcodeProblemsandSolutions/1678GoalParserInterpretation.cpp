/*
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order.
The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al".
The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string interpret(string command)
	{
		string strRet;
		int i = 0;
		int n = command.size();
		while (i < n)
		{
			if (command[i] == 'G')
			{
				strRet.push_back('G');
				++i;
				continue;
			}

			if (i + 1 < n && command[i] == '(' && command[i + 1] == ')')
			{
				strRet.push_back('o');
				i += 2;
				continue;
			}

			if (i + 3 < n && command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')')
			{
				strRet.append("al");
				i += 4;
				continue;
			}

			break;
		}

		return strRet;
	}
};

int main()
{
	std::vector<string> vctInput =
	{
		"G()(al)",
		"G()()()()(al)",
		"(al)G(al)()()G",
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it.c_str() << endl;
		string strRet = objSolution.interpret(it);
		cout << endl << "Output: " << strRet.c_str() << endl;
	}
}

/*

Input: G()(al)

Output: Goal

Input: G()()()()(al)

Output: Gooooal

Input: (al)G(al)()()G

Output: alGalooG

*/
