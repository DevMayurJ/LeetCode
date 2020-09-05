// Given an array of integers in sorted in ascending order
// Then find the first and last position of given target value. If target not found return [-1,-1]
// Eg: Input: [1,2,3,4,4,8] 
//     Output: [3,4]

#include<iostream>
#include<vector>
#include<bits/stdc++.h> 

using namespace std;

class Solution 
{
	public:
		vector<int> searchRange(vector<int>& vctNums, int iTarget) 
		{
		    int iSize = vctNums.size();
		    vector<int>::iterator it;
		    vector<int> vctResult = {-1,-1};
		    
		    if(iSize == 1)
		    {
		    	// If there is only one element in given array and the element is also the iTarget
		        if(vctNums[0] == iTarget)
		        {
		            vctResult[0] = 0;
		            vctResult[1] = 0;
		        }
		    }
		    else
		    {
				// Search for the iTarget in given array
				it = std::find(vctNums.begin(), vctNums.end(), iTarget);
				
				// If given iTarget is found
				if(it != vctNums.end())
				{
					int iPosition = it - vctNums.begin();		// Get the position(First position) of the iTarget 
					vctResult[0] = iPosition;			// Store first position in array
					
					// Finding the last position of iTarget
					while(iPosition < iSize)
					{
						// Move forward until the last position of iTarget is found
						if(iSize != iPosition + 1 && vctNums[iPosition + 1] == iTarget)
						{
							iPosition += 1;
						}
						else
						{
							//Store the last Position in result
							vctResult[1] = iPosition;
							break;
						}
					}
				}
		    }
		    return vctResult;
		}
};

int main()
{
	int i = 0;
	vector<vector<int>> vctInput = {
				{5, 7, 7, 8, 8, 10},
				{1, 2, 3, 5, 5, 5, 8},
			  	{1, 2, 2, 3},
			  	{9},
			  	{1, 1}
			     };
	vector<int> vctTargets = {8, 5, 2, 9, 3};
	vector<int> vctOutput;
	
	Solution objSolution;
		
	for(auto vct : vctInput)
	{
		vctOutput = objSolution.searchRange(vct, vctTargets[i]);
		
		cout<<endl<<"Input: [";
		
		for(auto no : vct)
		{
			cout<<no<<", ";
		}
		
		cout<<"\b\b]"<<"\tTarget: "<<vctTargets[i]<<endl<<"Output: [";
		
		for(auto pos : vctOutput)
		{
			cout<<pos<<",";
		}
		
		cout<<"\b]";
		i++;
		cout<<endl;
	}
	
	return 0;
}	
	
