/*
Given an array of intervals intervals where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
                return a[1] < b[1];
            });
        
        int iRet = 0;
        vector<int> vctPrev = intervals[0];
        for (auto it = intervals.begin() + 1; it != intervals.end(); ++it)
        {
            if (vctPrev[1] > (*it)[0])
            {
                ++iRet;
            }
            else
            {
                vctPrev = *it;
            }
        }
        
        return iRet;
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
    vector<vector<int>> vctInput = { {1,2},{2,3},{3,4},{1,3}};

    Solution objSolution;
    cout << endl << "Input: \n";

    for (size_t i = 0; i < vctInput.size(); ++i)
    {
        cout << "[";
        printArray(vctInput[i]);
        cout << "\b\b]";
    }

    int iRet = objSolution.eraseOverlapIntervals(vctInput);
    cout << "\nOutput: iRet=" << iRet ;

    return 0;
}

/*
Input: 
[1, 2][2, 3][3, 4][1, 3] 
Output: iRet=1
*/