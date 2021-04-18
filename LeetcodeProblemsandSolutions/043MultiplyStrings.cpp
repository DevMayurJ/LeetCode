/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		// handle edge-case where the product is 0
		if (num1 == "0" || num2 == "0") return "0";

		// num1.size() + num2.size() == max no. of digits
		vector<int> num(num1.size() + num2.size(), 0);

		// build the number by multiplying one digit at the time
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			for (int j = num2.size() - 1; j >= 0; --j)
			{
				num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
				num[i + j] += num[i + j + 1] / 10; //sperate carry and assign to next column
				num[i + j + 1] %= 10;
			}
		}

		// skip leading 0's
		int i = 0;
		while (i < num.size() && num[i] == 0) ++i;

		// transofrm the vector to a string
		string res = "";
		while (i < num.size()) res.push_back(num[i++] + '0');

		return res;
	}
};



int main()
{
	vector<string> vctInpString1 = {
					"2",
					"123",
					"0",
	};
	vector<string> vctInpString2 = {
					"3",
					"456",
					"0",
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString1.size(); ++i)
	{
		cout << "Input: num1 = \"" << vctInpString1[i] << "\"" << " num2 = \"" << vctInpString2[i] << "\"" << endl;
		cout << "Output: " << objSolution.multiply(vctInpString1[i], vctInpString2[i]) << endl;
	}
}

/*
Input: num1 = "2" num2 = "3"
Output: 6
Input: num1 = "123" num2 = "456"
Output: 56088
Input: num1 = "0" num2 = "0"
Output: 0
*/
