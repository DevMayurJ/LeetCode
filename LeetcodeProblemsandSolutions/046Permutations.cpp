/*
	Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
	
	Input: nums = [1,2,3]
	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
    	// Used Heaps algorithm to generate all possible permutations
        vector<vector<int>> permute(vector<int>& nums) 
        {
            int i = 1, iSize = nums.size();
            
            vector<int> vct(iSize, 0);
            vector<vector<int>> vctRes = {};
            vctRes.push_back(nums);
            
            while(i < iSize)
            {
                if(vct[i] < i)
                {
                    if(i % 2 == 0){
                        swap(nums[0], nums[i]);
                    }
                    else{
                        swap(nums[vct[i]], nums[i]);
                    }
                    vctRes.push_back(nums);
                    vct[i] += 1;
                    i = 1;
                }
                else
                {
                    vct[i] = 0;
                    ++i;
                }
            }
            
            return vctRes;
        }
};

void PrintArray(vector<int> vct)
{
	cout<<"[ ";
	for(auto x : vct)
	{
			cout<<x<<", ";
	}
	cout<<"\b\b]";
}

int main()
{
	vector<vector<int>> vctInput = {
								{1,2,3},
								{77,2},
								{51}
							};
							
	vector<vector<int>> vctOutput;
	Solution objSolution;
	for(auto vct : vctInput)
	{
		cout<<"\nInput: ";
		PrintArray(vct);
		
		vctOutput = objSolution.permute(vct);
		
		cout<<"\nOutput: [";
		for(auto op : vctOutput) 
		{
			PrintArray(op);
			cout<<", "; 
		}
		cout<<"\b\b]\n\n";
	}
	return 0;
}

/*
	Input: [ 1, 2, 3] 
	Output: [[ 1, 2, 3], [ 2, 1, 3], [ 3, 1, 2], [ 1, 3, 2], [ 2, 3, 1], [ 3, 2, 1]] 

	Input: [ 77, 2] 
	Output: [[ 77, 2], [ 2, 77]] 

	Input: [ 51] 
	Output: [[ 51]]
*/
