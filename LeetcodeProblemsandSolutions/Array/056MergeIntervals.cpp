/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> vctRet;
        //sort the elements
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (vctRet.empty() || vctRet.back()[1] < intervals[i][0])
            {
                //new unique entry found
                vector<int> vctTemp = { intervals[i][0], intervals[i][1] };
                vctRet.push_back(vctTemp);
            }
            else
            {
                //merge two sets
                vctRet.back()[1] = max(intervals[i][1], vctRet.back()[1]);
            }
        }

        return vctRet;
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
    vector<vector<int>> vctInput = { {1,3} ,{2,6},{8,10},{15,18}};

    Solution objSolution;
    cout << endl << "Input: \n";

    for (size_t i = 0; i < vctInput.size(); ++i)
    {
        cout << "[";
        printArray(vctInput[i]);
        cout << "\b\b]";
    }

    vector<vector<int>> vctOutput = objSolution.merge(vctInput);
    cout << "\nOutput: \n";
    for (size_t i = 0; i < vctOutput.size(); ++i)
    {
        cout << "[";
        printArray(vctOutput[i]);
        cout << "\b\b]";
    }

    return 0;
}

/*
Input:
[1, 3][2, 6][8, 10][15, 18]
Output:
[1, 6][8, 10][15, 18]
*/

/*
Time Complexity: O(NlogN) + O(N).
*/

