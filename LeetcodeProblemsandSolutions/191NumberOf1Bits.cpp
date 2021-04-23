/*
	Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
	
	Example 1:
		Input: n = 00000000000000000000000000001011
		Output: 3
		Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
	
	Example 2:
		Input: n = 00000000000000000000000010000000
		Output: 1
		Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int hammingWeight_SD(unsigned int n) 
        {
            int iCnt = 0;
            unsigned int iMask = 0x0000001;
			
            for(int i = 0; i < 32; ++i)
            {
			// If iMask & n results to iMask then the current bit is ON (eg 1011 & 0001 == 0001)
                if(((iMask & n) == iMask))
                {
                    iCnt++;
                }
			// Left Shift the ON bit in mask to check the next bit in Input
                iMask = iMask << 1;
            }

            return iCnt;
        }

		int hammingWeight(uint32_t n)
		{
			int iCnt = 0;
			while (n)
			{
				iCnt += n % 2;
				n >>= 1;
			}

			return iCnt;
		}
};


int main()
{
	vector<unsigned int> vctInput = {11, 2, 15, 12, 7, 9, 3, 37};
	int iRet = 0;
	Solution objSolution;
	
	for(auto it:vctInput)
	{
		iRet = objSolution.hammingWeight_SD(it);
		cout<<endl<<"Input: "<<it<<endl<<"Output SD: [ "<<iRet<<" ]"<<endl;
		iRet = objSolution.hammingWeight(it);
		cout << "Output MJ: [ " << iRet << " ]" << endl;
	}
	return 0;
}
