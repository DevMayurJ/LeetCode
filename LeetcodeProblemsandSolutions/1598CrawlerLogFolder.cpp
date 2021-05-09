/*
The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

"../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.



Example 1:



Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
Example 2:



Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
Example 3:

Input: logs = ["d1/","../","../","../"]
Output: 0
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int minOperations(vector<string>& logs)
	{
		int iRet = 0;
		for (int i = 0; i < logs.size(); ++i)
		{
			if (logs[i][0] == '.')
			{
				if (logs[i][1] == '.' && iRet > 0)
				{
					--iRet;
				}
			}
			else
			{
				++iRet;
			}
		}

		return iRet;
	}
};

void PrintVector(const vector<string>& vctInp)
{
	cout << "\nInput:";
	for (auto it : vctInp)
	{
		cout << it.c_str() << " ";
	}
}
int main()
{
	vector<vector<string>> vctInput =
	{
		{
			{"d1 / "},{"d2 / "},{".. / "},{"d21 / "},{". / "}
		},
		{
			{"d1/"}, {"d2/"},{"./"},{"d3/"},{"../"},{"d31/"}
		},
		{
			{"d1/"},{"../"}, {"../"}, {"../"}
		}
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		PrintVector(it);
		int iRet = objSolution.minOperations(it);
		cout << endl << "Output: " << iRet << endl;
	}
}

/*
Input:d1 /  d2 /  .. /  d21 /  . /
Output: 2

Input:d1/ d2/ ./ d3/ ../ d31/
Output: 3

Input:d1/ ../ ../ ../
Output: 0
*/
