// Consider 2 dominos A[i] and B[i] represent the top and bottom halves of the i-th domino.
// Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
// If no rotations are possible return -1

#include<iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

class Solution 
{
    public:
		    int MinDominoRotations(vector<int>& vctDomTop, vector<int>& vctDomBottom) 
		    {
				    int iNum1, iNum2;
				    int iNum1Freq, iNum2Freq;
				    int iDomTopSize = vctDomTop.size();
				    int iDomBtmSize = vctDomBottom.size();
				    
				    iNum1 = GetMostFreqNumber(vctDomTop, iDomTopSize);
				    iNum2 = GetMostFreqNumber(vctDomBottom, iDomBtmSize);
				    
				    iNum1Freq = count(vctDomTop.begin(), vctDomTop.end(), iNum1);
				    iNum2Freq = count(vctDomBottom.begin(), vctDomBottom.end(), iNum2);
				   
				   //Select the domino halve that has the highest frequency of a number
				   if(iNum1Freq > iNum2Freq)
				   { 
				      if(iNum1Freq == (iDomTopSize - FindPossibleRotations(vctDomTop, vctDomBottom, iNum1)))
				        	return (iDomTopSize - iNum1Freq);
				   }
				   else
				   {
				       if(iNum2Freq == (iDomBtmSize - FindPossibleRotations(vctDomBottom, vctDomTop, iNum2)))
				         	return (iDomBtmSize - iNum2Freq);
				   }     
		           return -1;
		    }
		
			//Find the possible number of times the domino can be rotated
		    int FindPossibleRotations(vector<int>& vctOne, vector<int>& vctTwo, int iKey)
		    {
				    int iSwapCnt = 0;
				    for(int i=0;i<vctOne.size();i++)
				    {
				          if(iKey != vctOne[i] && vctTwo[i] == iKey)
				              iSwapCnt++;
				    }  
				    return iSwapCnt;
		    }
		
			//Get the number with most Frequency from given domino half (represented as vector)
		    int GetMostFreqNumber(vector<int>& vctA, int iSize)
		    {
				    unordered_map<int, int> umNumAndFreq; 
				    int iMax = 0, iFreqNum; 
				    
				    for (int i = 0; i < iSize; i++) 
				    {
				        umNumAndFreq[vctA[i]]++; 
					}
				   
				    for (auto it : umNumAndFreq) 
				    { 
				        if (iMax < it.second) 
				        { 
				            iFreqNum = it.first; 
				            iMax = it.second; 
				        } 
				    } 
				    return iFreqNum; 
		    }
};

int main()
{
		Solution objSolution;
		int i=0;
		vector<int> vctTemp;
		vector<vector<int>> vctInputDomTop = 
						  {
							{3,5,1,2,3},  
						  	{2,1,2,4,2,2},
						  	{4,5,2,4,2}						  
						  };
		vector<vector<int>> vctInputDomBot = 
						  {
							{3,6,3,3,4},
						  	{5,2,6,2,3,2},
						  	{3,4,4,1,4}
						  };

							  
		cout << endl << "Input: {3,5,1,2,3}, {3,6,3,3,4} \nOutput: " << objSolution.MinDominoRotations(vctInputDomTop[0], vctInputDomBot[0]);
		cout << endl << "Input: {2,1,2,4,2,2}, {5,2,6,2,3,2} \nOutput: " << objSolution.MinDominoRotations(vctInputDomTop[1], vctInputDomBot[1]);
		cout << endl << "Input: {4,5,2,4,2}, {3,4,4,1,4} \nOutput: " << objSolution.MinDominoRotations(vctInputDomTop[2], vctInputDomBot[2]);
		cout << endl;
}
