/*
    The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
    Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
    using the following four rules:

    1) Any live cell with fewer than two live neighbors dies as if caused by under-population.
    2) Any live cell with two or three live neighbors lives on to the next generation.
    3) Any live cell with more than three live neighbors dies, as if by over-population.
    4) Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

    The next state is created by applying the above rules simultaneously to every cell in the current state, 
    where births and deaths occur simultaneously. 
    Given the current state of the m x n grid board, return the next state.


    Example:
            Input: board = [[1,1],[1,0]]
            Output: [[1,1],[1,1]]
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{   
    private:
        // Made dimensions of board as members of class to avoid
        // Passing of too many variables 
        int iRow, iCol;
    

        // Get count of live neighbors of a specified cell
		int GetLiveNeighbors(vector<vector<int>> vctGrid, int iRow, int iCol)
		{
			int iLiveCount = 0;
			vector<vector<int>> vctNeighbors = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

			/*		
				Positions of all 8 neighbours of given (row,col)
					(i-1,j-1) (i-1,j) (i-1,j+1)
					(i,j-1)	  (i,j)	  (i,j+1)
					(i+1,j-1) (i+1,j) (i+1,j+1)
			*/

			for(auto vct : vctNeighbors)
			{
				int x = vct[0] + iRow;
				int y = vct[1] + iCol;
				
				if((x >= 0) && (x < this->iRow) && (y >= 0) && (y < this->iCol) && (vctGrid[x][y] == 1))
				{
					iLiveCount++;
				}
			}
			
			return iLiveCount;
		}

    public:
        
        void gameOfLife(vector<vector<int>>& board) 
        {
            this->iRow = board.size();
            this->iCol = board[0].size();

            vector<vector<int>> vctNext(iRow, vector<int>(iCol, 0));
            
            for(int i = 0; i < iRow; ++i)
            {
                for(int j = 0; j < iCol; ++j)
                {
                    int iLiveCount = GetLiveNeighbors(board, i, j);
                    
                    if(board[i][j] == 1)
                    {
                        if((iLiveCount == 2 || iLiveCount == 3))
                        {
                            vctNext[i][j] = 1;
                        }
                    }
                    else if(board[i][j] == 0 && (iLiveCount == 3))
                    {
                        vctNext[i][j] = 1;
                    }
                }
            }
            
            board = vctNext;
        }
};

void printArray(vector<int> arr)
{
    for(auto x : arr)
    {
        cout<<x<<"\t";
    }

    cout<<"\n";
}


int main()
{
    vector<vector<int>> vctInput = {
                                {0,1,0},    
                                {0,0,1},
                                {1,1,1},
                                {0,0,0}
                            }; 

    Solution objSolution;

    cout<<"Input: \n";
    for(auto vct : vctInput)
    {
        cout<<"\t";
        printArray(vct);
    }

    objSolution.gameOfLife(vctInput);
    
    cout<<"\nOutput: \n";
    for(auto vct : vctInput)
    {
        cout<<"\t";
        printArray(vct);
    }

    return 0;
}

/*
    Input: 
            0   1   0   
            0   0   1   
            1   1   1   
            0   0   0   

    Output: 
            0   0   0   
            1   0   1   
            0   1   1   
            0   1   0
*/
