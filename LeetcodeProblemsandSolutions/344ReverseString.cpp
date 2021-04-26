/*
Write a function that reverses a string. The input string is given as an array of characters s.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s)
	{
		if (s.empty())
		{
			return;
		}

		int iStart = 0;
		int iEnd = s.size() - 1;
		while (iStart < iEnd)
		{
			char chTemp = s[iStart];
			s[iStart] = s[iEnd];
			s[iEnd] = chTemp;
			++iStart;
			--iEnd;
		}
	}
};

void PrintVector(const vector<char>& vctchar)
{
	cout << endl;
	for (auto ch : vctchar)
	{
		cout << "[ " << ch << "]";
	}
}

int main()
{
	vector<vector<char>> vctInput = {
		{'h','e','l','l','o'},
		{'H','a','n','n','a', 'h'}
		};

	Solution objSolution;
	for (auto str : vctInput)
	{
		cout << "\nInput: ";
		PrintVector(str);

		objSolution.reverseString(str);
		cout << "\nOutput: ";
		PrintVector(str);
	}

	return 0;
}

/*
Input:
[ h][ e][ l][ l][ o]
Output:
[ o][ l][ l][ e][ h]
Input:
[ H][ a][ n][ n][ a][ h]
Output:
[ h][ a][ n][ n][ a][ H]
*/
