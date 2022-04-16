/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<int> row(matrix.size(), 1);
        vector<int> col(matrix[0].size(), 1);

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[i].size(); ++j)
            {
                if (0 == matrix[i][j])
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[i].size(); ++j)
            {
                if (0 == row[i] || 0 == col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

void print2DArray(const vector<vector<int>>& matrix)
{
    cout << endl << "Matrix: \n";
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\b\b" << endl;
}

int main()
{
    vector<vector<int>> vctInput = {
        {0,1,2,0 },
        {3,4,5,2},
        {1,3,1,5 }
    };

    Solution objSolution;
    print2DArray(vctInput);

    objSolution.setZeroes(vctInput);
    cout << "Output:";
    print2DArray(vctInput);

    return 0;
}

/*
Matrix:
0 1 2 0
3 4 5 2
1 3 1 5

Output:
Matrix:
0 0 0 0
0 4 5 0
0 3 1 0
*/