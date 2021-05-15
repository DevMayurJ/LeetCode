/*
	Given an array nums of size n, return the majority element.

	The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		int majorityElement_SD(vector<int>& vctNums)
		{
			unordered_map<int, int> umNumAndFreq;
			int iSize = vctNums.size();
			int iMaxCnt = iSize >> 1;
			int iResult = 0;
			
			for(auto num : vctNums)
			{
				umNumAndFreq[num]++;
				if(umNumAndFreq[num] > iMaxCnt)
				{
					iResult = num;
				}
			}
			
			return iResult;
		}
		
		int majorityElement(vector<int>& vctNums)
    	{
        	unordered_map<int, int> umNumAndFreq; 
			int iMax = 0, iFreqNum; 
	        int iSize = vctNums.size();

			for(int i = 0; i < iSize; i++) 
			{
				umNumAndFreq[vctNums[i]]++; 
			}

			for(auto it : umNumAndFreq) 
			{ 
				if(iMax < it.second) 
				{
					iFreqNum = it.first; 
					iMax = it.second; 
				} 
			} 
			return iFreqNum;
    	}
};

void PrintArray(vector<int> vct)
{
	cout<<"[ ";
	for(auto x : vct)
	{
			cout<<x<<", ";
	}
	cout<<"\b\b]"<<endl;
}

int main()
{
	vector<vector<int>> vctInput = {
									{3,2,3,3,3,2},
									{2,2,1,1,1,2,2,1,1,1,2},
									{3,2,3},
									{2,2,1,1,1,2,2}
								};
	Solution objSolution;
				
	for(auto vct : vctInput)
	{
		cout<<"Input : ";
		PrintArray(vct);
		
		int iRet = objSolution.majorityElement_SD(vct);
		
		cout<<"Output : "<<iRet<<endl;
	}							
	return 0;
}

/*
	Input : [ 3, 2, 3, 3, 3, 2] 
	Output : 3
	
	Input : [ 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2] 
	Output : 1
	
	Input : [ 3, 2, 3] 
	Output : 3
	
	Input : [ 2, 2, 1, 1, 1, 2, 2] 
	Output : 2
*/
