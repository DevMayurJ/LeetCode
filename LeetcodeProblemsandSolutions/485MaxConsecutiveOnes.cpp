/*
    Given a binary array nums, return the maximum number of consecutive 1's in the array.

    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1's. 
                 The maximum number of consecutive 1's is 3.
*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class Solution 
{
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) 
        {
            int iOneCnt = 0;
            int iMaxCnt = INT_MIN;
            int iSize = nums.size();
            
            for(int i = 0; i < iSize; ++i)
            {
                if(nums[i] == 0)
                {
                    if(iOneCnt > iMaxCnt)
                    {
                        iMaxCnt = iOneCnt;
                    }
                    
                    // Reset current count of one's
                    iOneCnt = 0;
                    
                    // Skip zeroes until you find one
                    while((i+1 < iSize) && (nums[i+1] == 0))
                    {
                        i++;
                    }
                }
                else
                {
                    ++iOneCnt;
                }
            }
            
            // Check If the last window of one is larger than the ones before it
            if(iOneCnt > iMaxCnt)
            {
                iMaxCnt = iOneCnt;
            }
            
            return iMaxCnt;
        }
};

void printArray(vector<int> arr)
{
    cout<<"[ ";
    for(auto x : arr)
    {
        cout<<x<<", ";
    }

    cout<<"\b\b ]\n";
}

int main()
{
    vector<vector<int>> vctInput = {
                        {1,1,0,1,1,1},
                        {1,0,1,1,0,1},
                        {1,0,1,0,0,0,1,1,1,1,0},
                        {1,1,0,0,0,0}
                    };
    Solution objSolution;

    for(auto vct : vctInput)
    {
        cout<<"\nInput: ";
        printArray(vct);
        int iRet = objSolution.findMaxConsecutiveOnes(vct);
        cout<<"Output: "<<iRet<<endl;
    }
    return 0;
}

/*
    Input: [ 1, 1, 0, 1, 1, 1 ]
    Output: 3

    Input: [ 1, 0, 1, 1, 0, 1 ]
    Output: 2

    Input: [ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 ]
    Output: 4

    Input: [ 1, 1, 0, 0, 0, 0 ]
    Output: 2
*/
