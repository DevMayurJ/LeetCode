/*

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2)
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
			if (iVal > 9)
			{
				boCarry = true;
				iVal = iVal % 10;
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
			if (iVal > 9)
			{
				boCarry = true;
				iVal = iVal % 10;
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
			if (iVal > 9)
			{
				boCarry = true;
				iVal = iVal % 10;
			}

			strRet.push_back('0' + iVal);
			--j;
		}

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
					"456",
					"0",
	};
	vector<string> vctInpString2 = {
					"123",
					"77",
					"0",
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: num1 = \"" << vctInpString1[i] << "\"" << " num2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.addStrings(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: num1 = "11" num2 = "123"
Output: 134
Input: num1 = "456" num2 = "77"
Output: 533
Input: num1 = "0" num2 = "0"
Output: 0
*/
