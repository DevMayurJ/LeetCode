#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution 
{
    public:
        bool increasingTriplet(vector<int>& nums) 
        {
            int iSize = nums.size();
            int i = INT_MAX, j = INT_MAX;
            int iIndex = 0;
            
            if(iSize >= 3)
            {
                for(iIndex = 0; iIndex < iSize; ++iIndex)
                {
                    if(nums[iIndex] <= i)
                    {
                       i = nums[iIndex];
                    }
                    else if(nums[iIndex] <= j)
                    {
                        j = nums[iIndex];
                    }
                    else
                    {
                       break;
                    }
                }
                if(iIndex < iSize)
                {
                    return true;
                }
            }
            return false;            
        }
};

void printArray(vector<int> vctArr)
{
	for(auto it : vctArr)
	{
		cout<<it<<", ";
	}
}

int main()
{
	vector<vector<int>> vctInput = {
					{2, 5, 12, 7, 9},
					{17,18,3,4,6,1},
					{5,4,3,2,1},
					{90}
				};
	
	Solution objSolution;
	
	for(auto it:vctInput)
	{
		cout<<endl<<"Input: [ ";
		printArray(it);
		cout<<"\b\b]"<<endl;
		
		bool bRet = objSolution.increasingTriplet(it);
		
		cout<<"Output: "<<bRet<<endl;
	}
	return 0;
}

/*
	Input: [ 2, 5, 12, 7, 9] 
	Output: 1

	Input: [ 17, 18, 3, 4, 6, 1] 
	Output: 1

	Input: [ 5, 4, 3, 2, 1] 
	Output: 0

	Input: [ 90] 
	Output: 0
*/
