/*
	The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

	Given two integers x and y, return the Hamming distance between them.
	
	Input: x = 1, y = 4
	Output: 2
	Explanation:
	1   (0 0 0 1)
	4   (0 1 0 0)
		   ↑   ↑
	The above arrows point to positions where the corresponding bits are different.
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
	private:
		int CountOnBits(int iNum)
		{
			int iCnt = 0;
			unsigned int iMask = 0x00000001;
			
			for(int i = 0; i < 32; ++i)
			{
				if(((iMask & iNum) == iMask))
				{
					++iCnt;
				}
				iMask = iMask << 1;
			}
			
			return iCnt;
		}
	
	public: 
		int hammingDistance(int iNum1, int iNum2)
		{
			// 4  = 0 1 0 0    
		    // 10 = 1 0 1 0    
		    //-------------
		    // ^  = 1 1 1 0 = onBits = Hamming Distance = 3
		    
		    // 4  = 0 1 0 0
		    // 14 = 1 1 1 0
		    //--------------
		    // ^  = 1 0 1 0 = onBits = Hamming Distance = 2
		    
		    return CountOnBits(iNum1 ^ iNum2);
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
								{4,14},
								{4,2},
								{10,14},
								{8,34},
								{23,6}
							};
								
	Solution objSolution;
	for(auto it:vctInput)
	{
		cout<<endl<<"Input: [ ";
		printArray(it);
		cout<<"\b\b]"<<endl;
		
		int iDistance = objSolution.hammingDistance(it[0], it[1]);
		
		cout<<"Output: "<<iDistance<<endl;
	}
	return 0;
}

/*
	Input: [ 4, 14] 
	Output: 2

	Input: [ 4, 2] 
	Output: 2

	Input: [ 10, 14] 
	Output: 1

	Input: [ 8, 34] 
	Output: 3

	Input: [ 23, 6] 
	Output: 2

*/
