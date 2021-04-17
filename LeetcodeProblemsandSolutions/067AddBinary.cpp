/*

Given two binary strings a and b, return their sum as a binary string.
Example 1:

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string addBinary(string num1, string num2)
	{

		if (num1.empty())
		{
			return num2;
		}

		if (num2.empty())
		{
			return num1;
		}

		string strRet;
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		bool boCarry = false;
		while (i >= 0 && j >= 0)
		{
			int iVal = (num1[i] - '0') + (num2[j] - '0');
			if (boCarry)
			{
				++iVal;
			}

			boCarry = false;
			if (iVal > 1)
			{
				boCarry = true;
				if (iVal == 2) // 1 + 1 = 0
				{
					iVal = 0;
				}
				else    // 1 + 1 + 1 = 1 
				{
					iVal = 1;
				}
			}

			strRet.push_back('0' + iVal);
			--i;
			--j;
		}

		while (i >= 0)
		{
			int iVal = (num1[i] - '0');
			if (boCarry)
			{
				++iVal;
			}

			boCarry = false;
			if (iVal > 1)
			{
				boCarry = true;
				if (iVal == 2)
				{
					iVal = 0;
				}
				else
				{
					iVal = 1;
				}
			}

			strRet.push_back('0' + iVal);
			--i;
		}

		while (j >= 0)
		{
			int iVal = (num2[j] - '0');
			if (boCarry)
			{
				++iVal;
			}

			boCarry = false;
			if (iVal > 1)
			{
				boCarry = true;
				if (iVal == 2)
				{
					iVal = 0;
				}
				else
				{
					iVal = 1;
				}
			}

			strRet.push_back('0' + iVal);
			--j;
		}

		//add last carry if any
		if (boCarry)
		{
			strRet.push_back('0' + 1);
		}

		reverse(strRet.begin(), strRet.end());
		return strRet;
	}
};

int main()
{
	vector<string> vctInpString1 = {
					"11",
					"1010",
	};
	vector<string> vctInpString2 = {
					"1",
					"1011",
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: num1 = \"" << vctInpString1[i] << "\"" << " num2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.addBinary(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: num1 = "11" num2 = "1"
Output: 100
Input: num1 = "1010" num2 = "1011"
Output: 10101
*/
