/*

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order,
starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string mergeAlternately(string word1, string word2)
	{
		string strRet;
		int i = 0;
		int j = 0;
		int m = word1.size();
		int n = word2.size();
		int iCurr = -1;
		while (i < m && j < n)
		{
			strRet.push_back(word1[i]);
			strRet.push_back(word2[j]);
			++i;
			++j;
		}

		while (i < m)
		{
			strRet.push_back(word1[i]);
			++i;
		}

		while (j < n)
		{
			strRet.push_back(word2[j]);
			++j;
		}

		return strRet;
	}
};

int main()
{
	vector<string> vctInpString1 = {
					"abc",
					"ab",
					"abcd",
	};
	vector<string> vctInpString2 = {
					"pqr",
					"pqrs",
					"pq",
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: 1 = \"" << vctInpString1[i] << "\"" << " 2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.mergeAlternately(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: 1 = "abc" 2 = "pqr"
Output: apbqcr
Input: 1 = "ab" 2 = "pqrs"
Output: apbqrs
Input: 1 = "abcd" 2 = "pq"
Output: apbqcd
*/
