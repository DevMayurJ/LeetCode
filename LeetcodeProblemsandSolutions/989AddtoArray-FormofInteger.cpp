/*
he array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.



Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	vector<int> addToArrayForm(vector<int>& vctNo, int K)
	{
		vector<int> vctNo2;
		while (K > 0)
		{
			vctNo2.push_back(K % 10);
			K = K / 10;
		}

		reverse(vctNo2.begin(), vctNo2.end());

		int iCarry = 0;
		vector<int> vctRet;
		int i = vctNo.size() - 1;
		int j = vctNo2.size() - 1;
		while (i >= 0 && j >= 0)
		{
			int iVal = vctNo[i] + vctNo2[j];
			if (iCarry)
			{
				iVal = iVal + iCarry;
				iCarry = 0;
			}

			if (iVal > 9)
			{
				iCarry = iVal / 10;
				iVal = iVal % 10;
			}

			vctRet.push_back(iVal);
			--i;
			--j;
		}

		while (i >= 0)
		{
			int iVal = vctNo[i];
			if (iCarry)
			{
				iVal = iVal + iCarry;
				iCarry = 0;
			}
			if (iVal > 9)
			{
				iCarry = iVal / 10;
				iVal = iVal % 10;
			}

			vctRet.push_back(iVal);
			--i;
		}

		while (j >= 0)
		{
			int iVal = vctNo2[j];
			if (iCarry)
			{
				iVal = iVal + iCarry;
				iCarry = 0;
			}

			if (iVal > 9)
			{
				iCarry = iVal / 10;
				iVal = iVal % 10;
			}

			vctRet.push_back(iVal);
			--j;
		}

		while (iCarry)
		{
			vctRet.push_back(iCarry % 10);
			//vctRet.emplace(vctRet.begin(), iCarry % 10);
			iCarry = iCarry / 10;
		}

		reverse(vctRet.begin(), vctRet.end());
		return vctRet;
	}
};

void PrintVector(vector<int> vctInput)
{
	cout << "\n[";
	for (int val : vctInput)
	{
		cout << val << ",";
	}

	cout << "]";
}

int main()
{
	vector<vector<int>> vctInput1 = {
		{1,2,0,0},
		{2,7,4},
		{2,1,5 }
	};

	vector<int> vctInput2 = {
					34,
					181,
					806
	};

	Solution objSolution;
	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << "Input: num1 = ";
		PrintVector(vctInput1[i]);
		cout << "\nnum2 = \"" << vctInput2[i] << "\"" << endl;
		cout << "Output: ";
		vector<int> vctRet = objSolution.addToArrayForm(vctInput1[i], vctInput2[i]);
		PrintVector(vctRet);
	}
}

/*
Input: num1 =
[1,2,0,0,]
num2 = "34"
Output:
[1,2,3,4,]Input: num1 =
[2,7,4,]
num2 = "181"
Output:
[4,5,5,]Input: num1 =
[2,1,5,]
num2 = "806"
Output:
[1,0,2,1,]
*/

