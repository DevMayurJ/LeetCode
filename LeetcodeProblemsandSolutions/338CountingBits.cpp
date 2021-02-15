/*
 *  Given a non negative integer number num. Calculate the number of 1's in their binary
 *  representation for every number i in the range 0 ≤ i ≤ num  and return them as an array.
 *
 *      Example 1: Input: 5
 *	           Output: [0, 1, 1, 2, 1, 2] 
 *
 *	Example 2: Input: 12
 *		   Output: [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2] 
 */

#include<iostream>
#include <bitset>
#include<vector>

using namespace std;

class Solution
{
	public:
		vector<int> countBits(int num) 
		{
		    vector<int> vctOnes;
		    
		    for(int i = 0; i <= num; ++i)
		    {
		    	// Convert decimal to binary 
		        std::bitset<64> b(i);		// Size is set to 64 so that we don't miss any bits for large numbers
		        vctOnes.push_back(b.count());	// count() returns the number of one's in the binary number
		    }
		    
		    return vctOnes;
		}
};

int main()
{
	vector<int> vctInput = {2, 5, 12, 7, 9};
	vector<int>	vctOutput;
	Solution objSolution;
	for(auto it:vctInput)
	{
		vctOutput = objSolution.countBits(it);
		cout<<endl<<"Input: "<<it<<endl<<"Output: [";
		for(auto op : vctOutput)
		{
			cout<<op<<", ";
		}
		cout<<"\b\b]"<<endl;
	}
	return 0;
}
