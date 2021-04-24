/*
	Given an integer num, return a string representing its hexadecimal representation.

	All the letters in the answer string should be lowercase characters, 
	and there should not be any leading zeros in the answer except for the zero itself.	
	
	Example 1:
		Input: num = 26
		Output: "1a"

	Could you solve it without using any built-in library method?
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution 
{
    public:
        string toHex_SD(int iNum) 
        {
            if (iNum == 0)
            {
                return "0"; 
            }
            // Set all bits of last nibble of iMask to 1
            // So that we can extract the just one nibble from iNum using & operator
            int iMask = 0x0000000F;
            
            string strHex = "0123456789abcdef"; 
            string strResult;
            
            for (int i = 0; iNum != 0 && i < 8; ++i)
            {
            	// iNum & iMask will give index of its Hex representation from strHex
            	// then store Hex in strResult
                strResult = strHex[iNum & iMask] + strResult;	
                // Left shift by 4 bits to get next nibble
                iNum = iNum >> 4; 
            }
            
            return strResult;
        }
};

int main()
{
	vector<int> vctInput = {11, -1, 15, 12, 7, 26, 3, 37};
	string strRet;
	Solution objSolution;
	
	for(auto it:vctInput)
	{
		strRet = objSolution.toHex_SD(it);
		cout<<endl<<"Input: "<<it<<endl<<"Output: [ "<<strRet<<" ]"<<endl;
	}
	return 0;
}
