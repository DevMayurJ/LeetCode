// Given an array of digits of non-negative integers increment one to the integer
// Eg: [1,2,3] => [1,2,4]
//	   [2,9,9] => [3,0,0]

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
		public:
			vector<int> plusOne(vector<int>& vctDigits) 
			{
				int iSize = vctDigits.size();
				int iIndex;

				for (iIndex = (iSize - 1); iIndex >= 0; iIndex--)
				{
				    if(vctDigits[iIndex] == 9)
				    {
				    	vctDigits[iIndex] = 0;
				    }
				    else		//If the digit is not 9 then just increment the digit by 1 and break out of the loop (Eg: 123, 224 etc)
				    {
				    	vctDigits[iIndex]++;
				    	break;
				    }
				}

				if(vctDigits[0] == 0)
				{
					vctDigits.insert(vctDigits.begin(), 1);
				}

				return vctDigits;
			}
};

int main()
{
	Solution objSolution;
	vector<int> vctOutput;
	vector<vector<int>> vctInput = {
						{9, 9, 9},
					  	{2, 4, 3},
					  	{9},
					  	{2},
					  	{9, 9}
					  };

	for (auto it : vctInput)
	{
		cout << endl << "Input:  ";
		for (auto no : it)
		{
			cout << no << "\t";
		}

		vctOutput = objSolution.plusOne(it);
		cout << endl << "Output: ";
		for (auto outIt : vctOutput)
		{
			cout << outIt << "\t";
		}
		cout << endl;
	}
	return 0;
}
