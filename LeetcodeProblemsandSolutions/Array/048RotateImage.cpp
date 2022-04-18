/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        //transpose matrix i.e row to column shift       
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse each rows
        for (int i = 0; i < matrix.size(); ++i)
        {
            int iColStart = 0;
            int iColEnd = matrix[i].size() - 1;
            while (iColStart < iColEnd)
            {
                swap(matrix[i][iColStart], matrix[i][iColEnd]);
                ++iColStart;
                --iColEnd;
            }
        }
    }
};

void printArray(vector<int> vctArr)
{
    for (auto it : vctArr)
    {
        cout << it << ", ";
    }
}

int main()
{
    vector<vector<int>> vctInput = {
                        {1,2,3,},
                        {4,5,6},
                        {7,8,9}
    };

    Solution objSolution;
    cout << endl << "Input: \n";

    for (size_t i = 0; i < vctInput.size(); ++i)
    {
        cout << "[";
        printArray(vctInput[i]);
        cout << "\b\b]" << endl;
    }

    objSolution.rotate(vctInput);
    cout << "Output: \n";
    for (size_t i = 0; i < vctInput.size(); ++i)
    {
        cout << "[";
        printArray(vctInput[i]);
        cout << "\b\b]" << endl;
    }

    return 0;
}

/*
Input:
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
Output:
[7, 4, 1]
[8, 5, 2]
[9, 6, 3]
*/