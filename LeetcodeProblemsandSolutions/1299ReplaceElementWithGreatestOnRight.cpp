/*
 *	Given an array, replace every element with the greatest number to its right and replace the last element with -1. 
 *  Then return the array.
 *  
 *  Example: Input: arr = [17,18,5,4,6,1]
 *			 Output: [18,6,6,6,1,-1]
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
		public:
			vector<int> replaceElements(vector<int>& vctNums) 
			{
				int i;
				int iPrevMax = 0;
				int iSize = vctNums.size();
				if(iSize != 1)
				{
					for(i = 0; i < iSize; ++i)
					{
						// Don't calculate max if the the current element is less than previous max .
						if(iPrevMax <= vctNums[i])
						   iPrevMax = *max_element((vctNums.begin() + (i+1)), vctNums.end()); 
						vctNums[i] = iPrevMax;
					}
				}
				vctNums[iSize - 1] = -1;
				return vctNums;
			}
			
				vector<int> replaceElements_MJ(vector<int>& arr)
	{
		vector<int> vctRet;

		for (int i = 0; i < arr.size() - 1; ++i)
		{
			int iMax = arr[i + 1];
			for (int j = i + 1; j < arr.size(); ++j)
			{
				if (arr[j] > iMax)
				{
					iMax = arr[j];
				}
			}

			vctRet.push_back(iMax);
		}

		vctRet.push_back(-1);
		return vctRet;
	}
};

void printArray(vector<int> vctArr)
{
		for(auto it : vctArr)
		{
			cout<<it<<", ";
		}
}

int main()
{
		vector<vector<int>> vctInput = {
								{2, 5, 12, 7, 9},
								{17, 18, 5, 4, 6, 1},
								{120, 32},
								{90}
							};
		
		vector<int>	vctOutput;
		Solution objSolution;
		
		for(auto it:vctInput)
		{
			cout<<endl<<"Input: [ ";
			printArray(it);
			cout<<"\b\b]"<<endl;

			vctOutput = objSolution.replaceElements(it);

			cout<<"Output: [ ";
			printArray(vctOutput);
			cout<<"\b\b]"<<endl;
		}
		return 0;
}
