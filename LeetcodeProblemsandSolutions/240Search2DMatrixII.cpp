/*
	Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

    -Integers in each row are sorted in ascending from left to right.
    -Integers in each column are sorted in ascending from top to bottom.
*/

#include<iostream>
#include<vector>

using namespace std;
    
class Solution 
{
	private:
		bool SearchTarget(vector<vector<int>>& vctMatrix, int iTarget, int iRow, int iCol)
		{
			int i = 0;
			
			// Base case
			if(iRow < 0 || iCol < 0)
			{
				return false;
			}
			
			// Row search
			for(i = 0; i <= iCol; ++i)
			{
				if(vctMatrix[iRow][i] == iTarget)
				{
					return true;
				}
			}
			
			// Column search
			for(i = 0; i <= iRow; ++i)
			{
				if(vctMatrix[i][iCol] == iTarget)
				{
					return true;
				}
			}
			
			return SearchTarget(vctMatrix, iTarget, iRow - 1, iCol - 1);
		}
		
	public:
		// Bruteforce search
		bool searchMatrix(vector<vector<int>>& vctMatrix, int iTarget)
		{ 
		    int iRows = vctMatrix.size()-1;
		    int iCols = vctMatrix[0].size()-1;
		    
		    return SearchTarget(vctMatrix, iTarget, iRows, iCols);
		}
		
		bool searchMatrix_SD(vector<vector<int>>& vctMatrix, int iTarget)
		{ 
		    int m = vctMatrix.size(), iRow = 0;
		    int n = vctMatrix[0].size(), iCol = n - 1;
		    
			// We will satrt searching from last column
		    while(iRow < m && iCol >= 0)
		    {
		    	// If target found return true
		    	if(vctMatrix[iRow][iCol] == iTarget)
		    	{
		    		return true;
		    	}
		    	else if(vctMatrix[iRow][iCol] < iTarget)
		    	{
		    		// If current element is less than target
		    		// then move to next row in same column because 
		    		// we will not find target in that row as elements are sorted
		    		++iRow;
		    	}
		    	else
		    	{
		    		// Columns are sorted top-bottom
		    		// so if current element is greater than target
		    		// we discard the whole column and move to next
		    		--iCol;
		    	}
		    }
		    
		    return false;
		}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30}
	};

	vector<int> vctTargets =
	{
		2,			// True
		5,			// True
		9,			// True
		29,			// False
		23, 		// True
		121			// False
	};

	Solution objSolution;
	bool bOutput = false;
	
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
	
	for(auto test : vctTargets)
	{
		bOutput = objSolution.searchMatrix_SD(vctInput, test);
		cout<<"\nOutput for Target: "<<test<<": "<<bOutput<<endl;
	}		
}
/*
	Input: matrix = [ 1,4,7,11,15]
					[ 2,5,8,12,19]
					[ 3,6,9,16,22]
					[ 10,13,14,17,24]
					[ 18,21,23,26,30]
		
	Output for Target: 2: 1

	Output for Target: 5: 1

	Output for Target: 9: 1

	Output for Target: 29: 0

	Output for Target: 23: 1

	Output for Target: 121: 0
*/
