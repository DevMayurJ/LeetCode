/*
	Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

	Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		vector<int> majorityElement_SD(vector<int>& vctNums)
		{
			unordered_map<int, int> umNumAndFreq;
			int iSize = vctNums.size();
			int iMinCnt = iSize / 3;
			
			vector<int> vctResult;
			
			for(auto num : vctNums)
			{
				umNumAndFreq[num]++;
				if((umNumAndFreq[num] > iMinCnt) && (std::find(vctResult.begin(),vctResult.end(),num) == vctResult.end()))
				{
					vctResult.push_back(num);
				}
			}
			
			return vctResult;
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
									{3, 2, 3, 3, 3, 2},
									{1},
									{3,2,3},
									{2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2},
									{1,2}
								};
	Solution objSolution;
	vector<int> vctOutput;
	for(auto vct : vctInput)
	{
		cout<<"Input : ";
		PrintArray(vct);
		
		vctOutput = objSolution.majorityElement_SD(vct);
		
		cout<<"Output : ";
		PrintArray(vctOutput);
		cout<<endl;
	}							
	return 0;
}

/*
	Input : [ 3, 2, 3, 3, 3, 2] 
	Output : [ 3] 

	Input : [ 1] 
	Output : [ 1] 

	Input : [ 3, 2, 3] 
	Output : [ 3] 

	Input : [ 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2] 
	Output : [ 2, 1] 

	Input : [ 1, 2] 
	Output : [ 1, 2]
*/
