/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
            sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
                return a[1] < b[1];
            });
        
        int iRet = 0;
        vector<int> vctPrev = points[0];
        for (auto it = points.begin() + 1; it != points.end(); ++it)
        {
            if (vctPrev[1] >= (*it)[0])
            {
                ++iRet;
            }
            else
            {
                vctPrev = *it;
            }
        }
        
        return points.size() - iRet;
        
    }
};


void printArray(vector<int> vctArr)
{
    for (auto it : vctArr)
    {
        cout << it << ", ";
    }
}

void Test(vector<vector<int>> vctInput)
{
    Solution objSolution;
    cout << endl << "Input: \n";

    for (size_t i = 0; i < vctInput.size(); ++i)
    {
        cout << "[";
        printArray(vctInput[i]);
        cout << "\b\b]";
    }

    int iRet = objSolution.findMinArrowShots(vctInput);
    cout << "\nOutput: iRet=" << iRet ;
}

int main()
{
    vector<vector<int>> vctInput1 = { {10,16},{2,8},{1,6},{7,12}};
    Test(vctInput1);

    vector<vector<int>> vctInput2 = { {1,2},{3,4},{5,6},{7,8}};
    Test(vctInput2);

    vector<vector<int>> vctInput3 = { {1,2},{2,3},{3,4},{4,5}};
    Test(vctInput3);
    
    return 0;
}

/*
Input: 
[10, 16][2, 8][1, 6][7, 12] 
Output: iRet=2
Input: 
[1, 2][3, 4][5, 6][7, 8] 
Output: iRet=4
Input: 
[1, 2][2, 3][3, 4][4, 5] 
Output: iRet=2
*/