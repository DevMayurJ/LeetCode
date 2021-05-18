/* 
	Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
	return the number of negative numbers in grid. 	
	
	Input: grid = [[3,2],[1,0]]
	Output: 0

	Input: grid = [[1,-1],[-1,-1]]
	Output: 3
*/

#include<iostream>
#include<vector>

using namespace std;
    
class Solution 
{
	public:
		int countNegatives(vector<vector<int>>& vctGrid)
		{
			int iRow = vctGrid.size();
			int iCol = vctGrid[0].size();
			int i = 0, j = iCol - 1, iCnt = 0;
			
			while(i < iRow && j >= 0)
			{
				// Matrix is sorted in decreasing order both row wise and column wise
				// if current element is negative then its whole column below is negative
				// so we count total negative numbers and move to next column
				if(vctGrid[i][j] < 0)
				{
					iCnt = iCnt + (iRow - i);
					--j;
				}
				else
				{
					// if current element is positive then we move to next row 
					// To find lesser number
					++i;
				}
			}
			
			return iCnt;
		}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{4,3,2,-1},
		{3,2,1,-1},
		{1,1,-1,-2},
		{-1,-1,-2,-3}
	};

	Solution objSolution;
	cout << "\nInput: matrix = ";
	for(auto vct : vctInput)
	{
		cout<<"[ ";
		for(auto i : vct)
		{
			cout << i << ",";
		}
		cout<<"\b]"<<endl;
		cout<<"\t\t";
	}
	
	int iRet = objSolution.countNegatives(vctInput);
	cout<<"\nOutput: "<<iRet<<endl;		
}

/*
	Input: matrix = [ 4,3,2,-1]
		            [ 3,2,1,-1]
		            [ 1,1,-1,-2]
		            [ -1,-1,-2,-3]

	Output: 8

*/
