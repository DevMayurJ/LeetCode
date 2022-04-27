/*
ou are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow_O_KN(vector<int>& nums, int k)
	{
		//Time Limit Exceeded
		vector<int> vctRet;
		int n = nums.size();

		for (int i = 0; i <= n - k; ++i)
		{
			int iMax = nums[i];
			for (int j = i + 1; j < i + k; ++j)
			{
				if (iMax < nums[j])
				{
					iMax = nums[j];
				}
			}

			vctRet.push_back(iMax);
		}

		return vctRet;
	}


	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		//store curr windows MAX elements index in front of the array 
		deque<int> dqMaxEltIndex;
		vector<int> vctRet;
		for (int i = 0; i < nums.size(); i++)
		{
			//cout << "\ni=" << i;
			// As the window move on, Max element index nums[left-k] will be outdated.
			if (!dqMaxEltIndex.empty() && dqMaxEltIndex.front() == i - k)
			{
				//cout << "\nremoving max index out of windows=" << dqMaxEltIndex.front();
				dqMaxEltIndex.pop_front();
			}

			// Now we are ready to push our new element nums[left]'s index into the queue.
			// But before that, we should clear elements which is smaller then nums[left].
			 //remove all sammler elements from queue
			while (!dqMaxEltIndex.empty() && nums[dqMaxEltIndex.back()] < nums[i])
			{
				//cout << "\tremoving dqMaxEltIndex.back()=" << dqMaxEltIndex.back() << " elm=" << nums[dqMaxEltIndex.back()];
				dqMaxEltIndex.pop_back();
			}

			// Now push curr index into our queue.
			dqMaxEltIndex.push_back(i);
			if (i >= k - 1)
			{
				// Now nums[queue.front()] mush be the max number in range WINDOW(left-k, left] 
				vctRet.push_back(nums[dqMaxEltIndex.front()]);
				//cout << "\t Store current windows max=" << nums[dqMaxEltIndex.front()];
			}
		}

		return vctRet;
	}
};

int main()
{
	vector<vector<int>> vctInput1 =
	{
		{1,3,-1,-3,5,3,6,7 },
		{1},
		{1,-1},
		{9,11},
		{4,-2}
	};

	vector<int> vctInput2 = { 3,1,1,2,2 };

	Solution objSolution;
	for (int i = 0; i < vctInput1.size(); ++i)
	{
		cout << endl << "Input: ";
		for (auto no : vctInput1[i])
		{
			cout << no << "\t";
		}

		cout << endl << "Input2: Windows size=" << vctInput2[i];

		vector<int> vctRet = objSolution.maxSlidingWindow(vctInput1[i], vctInput2[i]);
		cout << endl << "Output: " << "\t\t\tArray is: ";
		for (int j = 0; j < vctRet.size(); ++j)
		{
			cout << vctRet[j] << "\t";
		}

		vector<int> vctRet1 = objSolution.maxSlidingWindow_O_KN(vctInput1[i], vctInput2[i]);
		cout << endl << "Output Brute Force solution: " << "\tArray is: ";
		for (int j = 0; j < vctRet1.size(); ++j)
		{
			cout << vctRet1[j] << "\t";
		}

		cout << endl;
	}
}

/*
Input: 1        3       -1      -3      5       3       6       7
Input2: Windows size=3
Output:                         Array is: 3     3       5       5       6       7
Output Brute Force solution:    Array is: 3     3       5       5       6       7

Input: 1
Input2: Windows size=1
Output:                         Array is: 1
Output Brute Force solution:    Array is: 1

Input: 1        -1
Input2: Windows size=1
Output:                         Array is: 1     -1
Output Brute Force solution:    Array is: 1     -1

Input: 9        11
Input2: Windows size=2
Output:                         Array is: 11
Output Brute Force solution:    Array is: 11

Input: 4        -2
Input2: Windows size=2
Output:                         Array is: 4
Output Brute Force solution:    Array is: 4
*/
