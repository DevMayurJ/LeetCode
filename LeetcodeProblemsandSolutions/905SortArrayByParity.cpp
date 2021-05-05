/*
	Given an array A of non-negative integers, return an array consisting of all the even elements of A, 
	followed by all the odd elements of A.

	You may return any answer array that satisfies this condition.
	
	Example 1:

	Input: [3,1,2,4]
	Output: [2,4,3,1]
	The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

*/
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
	public:
		vector<int> sortArrayByParity(vector<int>& vctNums)
		{
			int iCurr = 0;
			int iEnd = 	vctNums.size()-1;
			
			while(iCurr < iEnd)
			{
				if((vctNums[iCurr] % 2 == 0))
				{
					++iCurr;
				}
				else if((vctNums[iCurr] % 2 != 0) && (vctNums[iEnd] % 2 == 0))
				{
					std::swap(vctNums[iCurr], vctNums[iEnd]);
					++iCurr;
					--iEnd;
				}
				else
				{
					--iEnd;
				}
			}
			
			return vctNums;
		}
};

void Print(vector<int> vctArr)
{
	for(auto it : vctArr)
	{
		cout<<it<<", ";
	}
}

int main()
{
	vector<vector<int>> vctInput = {
							{3, 1, 2, 4},
							{2, 5, 12, 7, 9, 11, 14},
							{2, 5, 12, 7, 8},
							{17, 18, 5, 4, 6, 1},
							{1},
							{9, 90}
						};
	vector<int>	vctOutput;
	Solution objSolution;
	
	for(auto it:vctInput)
	{
		cout<<endl<<"Input: [ ";
		Print(it);
		cout<<"\b\b]"<<endl;
		
		vctOutput = objSolution.sortArrayByParity(it);
		
		cout<<"Output: [ ";
		Print(vctOutput);
		cout<<"\b\b]"<<endl;
	}
}
/*
	Input: [ 3, 1, 2, 4] 
	Output: [ 4, 2, 1, 3] 

	Input: [ 2, 5, 12, 7, 9, 11, 14] 
	Output: [ 2, 14, 12, 7, 9, 11, 5] 

	Input: [ 2, 5, 12, 7, 8] 
	Output: [ 2, 8, 12, 7, 5] 

	Input: [ 17, 18, 5, 4, 6, 1] 
	Output: [ 6, 18, 4, 5, 17, 1] 

	Input: [ 1] 
	Output: [ 1] 

	Input: [ 9, 90]
	Output: [ 90, 9] 
*/
