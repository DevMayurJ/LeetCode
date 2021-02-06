/*
 *	Given a list of numbers compressed with run-length encoding
 *  	In the list each adjacent pair is in format [freq, val]
 *  	To decompress the list you will create a new list where each [val] from compressed list will be repeated [freq] times.
 *
 *	Example: Input: nums = [1,2,3,4]
 *			 Output: [2,4,4,4]
 * 		Here the adjacent pairs will be [1,2] and [3,4] 
 *		so the list will decompress to [2, 4, 4, 4]
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
        vector<int> decompressRLElist(vector<int>& vctNums) 
        {
            vector<int> vctDecompressedList;
            int iSize = vctNums.size();
            for(int i = 0; i < iSize - 1; i+=2)
            {
                for(int j = 0; j < vctNums[i]; ++j)
		{
                    vctDecompressedList.push_back(vctNums[i + 1]);
                }
            }
            
            return vctDecompressedList;
        }
};

int main()
{
	vector<vector<int>> vctInput = {
						{1,2,3,4},		// [2,4,4,4]
						{2,5,6,1,3,-1},	// [5,5,1,1,1,1,1,1,-1,-1,-1]
					};
	vector<int> vctOutput;					
	Solution objSolution;
	
	for(auto list:vctInput)
	{
		cout<<endl<<"Compressed List = [";
		for(auto l : list)
		{
			cout<<l<<",";
		}	
		cout<<"\b]"<<endl;
		vctOutput = objSolution.decompressRLElist(list);
		cout<<"Decompressed List = [";
		for(auto op : vctOutput)
		{
			cout<<op<<",";
		}
		cout<<"\b]"<<endl;
	}
	return 0;
}
