/*
11. Container With Most Water
Medium

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int iLeft = 0;
		int iRight = height.size() - 1;
		int iMaxArea = 0;
		while (iLeft < iRight)
		{
			if (height[iLeft] < height[iRight])
			{
				iMaxArea = max(iMaxArea, height[iLeft] * (iRight - iLeft));
				iLeft++;
			}
			else
			{
				iMaxArea = max(iMaxArea, height[iRight] * (iRight - iLeft));
				--iRight;
			}
		}

		return iMaxArea;
	}
	
    int maxArea_sumeet(vector<int>& height) 
    {
        int l = 0;
        int r = height.size() - 1;
        int b = 0;
        int maxarea = 0;
        while (l < r)
        {
            b = min(height[l], height[r]);
            maxarea = max (maxarea, (r - l) * b);
            while (l < r && b >= height[l])
            {
                ++l;
            }
            
            while (r > l && b >= height[r])
            {
                --r;
            }                        
        }
        
        return maxarea;
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
	vector<vector<int>> vctInput1 = {
								{1,8,6,2,5,4,8,3,7},
								{1,1},
								{4,3,2,1,4},
								{1,2,1}
	};

	Solution objSolution;
	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << endl << "Input: [ ";
		printArray(vctInput1[i]);
		cout << "\b\b]" << endl;
		int iRet = objSolution.maxArea(vctInput1[i]);

		cout << "Output: " << iRet << endl;
	}
	return 0;
}

/*
Output:

Input: [ 1, 8, 6, 2, 5, 4, 8, 3, 7]
Output: 49

Input: [ 1, 1]
Output: 1

Input: [ 4, 3, 2, 1, 4]
Output: 16

Input: [ 1, 2, 1]
Output: 2

*/

