/*	Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
 *	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically (diagonally not allowed).
 *
 *  Example: 
 *  			Input: grid = [
 *					  		["1","1","1","1","0"],
 *					  		["1","1","0","1","0"],
 *					  		["1","1","0","0","0"],
 *							["0","0","0","0","0"]
 *							]
 *				Output: 1
 *  
 *				Input: grid = [
 *							  ["1","1","0","0","0"],
 *							  ["1","1","0","0","0"],
 *							  ["0","0","1","0","0"],
 *							  ["0","0","0","1","1"]
 *							]
 *				Output: 3
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
			int numIslands(vector<vector<char>>& vctGrid)  
			{
				int iCount = 0;
				int iRows = vctGrid.size();
				int iCols = vctGrid[0].size();
	
				for(int i=0; i < iRows; ++i)
				{
				    for(int j = 0; j < iCols; ++j)
				    {
				        if(vctGrid[i][j] == '1')
				        {
				        	++iCount;
				        	CheckForIsland(vctGrid,i,j);
				        }
				    }
				}
				return iCount;
			}
			
			void CheckForIsland(vector<vector<char>>& vctGrid, int i, int j)
			{
				if(j<0 || j >=vctGrid[i].size() || i < 0 || i >=vctGrid.size() || vctGrid[i][j] == '0')
					return;
				
				vctGrid[i][j] = '0';	// Make the '1' we found '0'  
				
				// Then check for other '1's.	
				CheckForIsland(vctGrid, i + 1, j);	// Down
				CheckForIsland(vctGrid, i - 1, j);	// Up
				CheckForIsland(vctGrid, i, j - 1);	// Left
				CheckForIsland(vctGrid, i, j + 1);	// Right
			}
};

int main()
{

	vector<vector<char>> vctInput = {
										{'1','1','1','1','0'},		
										{'1','1','0','1','0'},		
										{'1','1','0','0','0'},	
										{'0','0','0','0','0'}
									};	//Output Should be 1
	vector<vector<char>> vctInput2 = {
										{'1','1','1','1','0'},		
										{'1','1','0','0','0'},		
										{'0','0','1','1','0'},	
										{'1','0','0','0','0'}
									};	//Output Should be 3
							
	Solution objSolution;
	cout<<"Number of Islands in 1st Grid: "<<objSolution.numIslands(vctInput);
	cout<<"\nNumber of Islands in 2nd Grid: "<<objSolution.numIslands(vctInput2)<<"\n";
	return 0;
}
