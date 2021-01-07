/*
 *	We have two special characters. 
 *  First can be represented by 1 bit and the second with 2 bits. (10 or 11)
 *  Now given a string represented by several bits. Check if the last character must 
 *  be One bit or Wwo bits
 *
 * Example:	
 * 			Input: bits = [1, 0, 0]
 * 			Output: True 
 *
 *			Input: bits = [1, 1, 1, 0]
 *			Output: False
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
	public:
		bool IsOneBitCharacter(vector<int>& vctBits) 
		{
		    int iSize = vctBits.size();
		    bool bOneBit = false;
		    for(int i = 0; i < iSize; ++i)
		    {
		        if(i + 1 != iSize)
		        {
		            if(vctBits[i] == 1 && (vctBits[i + 1] == 0 || vctBits[i + 1] == 1))
		            {
		                ++i;
		            }  
		        }
		        else
		        {
		            bOneBit = true;
		            break;
		        }
		    }
		    return bOneBit;
		}
};

int main()
{
	vector<vector<int>> vctInput = {
										{1,1,1,0},		// Should return false
										{1,0},			// Should return false
										{0,0,1,0,1},	// Should return true
										{1,0,0}		    // should return true
									};
	bool bOutput;							
	Solution objSolution;	
			
	for(auto vct : vctInput)
	{
		cout << "\nInput: bits = [";
		for(auto i : vct)
		{
			cout << i << ",";
		}
		bOutput = objSolution.IsOneBitCharacter(vct);
		cout<<"\b]\nOutput: "<<bOutput<<"\n";
	}		
		cout<<"\n";						
}
