#include <iostream>
#include <vector>
using namespace std;

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution
{
public:
	string intToRoman(int num)
	{
		vector<string> vctI = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };//1-9
		vector<string> vctX = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };//10-90
		vector<string> vctC = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };//100-900
		vector<string> vctM = { "", "M", "MM", "MMM" };   //MAX 3000 possible

		string strM = vctM[num / 1000];
		num = num % 1000;
		string strC = vctC[num / 100];
		num = num % 100;
		string strX = vctX[num / 10];
		string strI = vctI[num % 10];

		return strM + strC + strX + strI;
	}
};

int main()
{
	std::vector<int> vctInput =
	{
		3,
		1994,//MCMXCIV
		4,
		58,
		9
	};

	Solution objSolution;
	for (auto it : vctInput)
	{
		cout << endl << "Input: " << it << endl;
		string strRet = objSolution.intToRoman(it);
		cout << endl << "Output: " << strRet.c_str() << endl;
	}
}

/*
Input: 3

Output: III

Input: 1994

Output: MCMXCIV

Input: 4

Output: IV

Input: 58

Output: LVIII

Input: 9

Output: IX
*/
