 /* 
 	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 		- Integers in each row are sorted from left to right.
 		- The first integer of each row is greater than the last integer of the previous row.
 
   	Example: Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
		 Output: true
  		 
  	 The elements in given matrix are in sorted order so
         We'll use divide and conquer approach of Binary search algorithm
          
         Step 1 (Divide): Divide the matrix in rows as sub array's
                          if sub_arr[start] <= target <= sub_arr[end] then
                               return BinarySearch(sub_arr, start, end, target)
                          else 
                              select next sub_arr i.e next row and repeat. 
                              
          Step 2 (Search): BinarySarch(sub_arr, low, high, target)
                            {
                                if(high > low) then
                                {
                                    if sub_arr[0] == target then
                                        return 0
                                    else
                                        mid = (low + high)/2
                                        if(sub_arr[mid] == target)
                                            return mid;
                                        else if target < sub_arr[mid]
                                            return BinarySearch(sub_arr, low, mid - 1, target)
                                      else 
                                            return BinarySearch(sub_arr, mid+1, high, target)
                                 }
                                return false
                            }   
                         
  */
#include<iostream>
#include<vector>

using namespace std;
    
class Solution 
{
	public:
		bool searchMatrix(vector<vector<int>>& vctMatrix, int iTarget)
		{ 
		    bool bFlag = false;
		    int iEnd = vctMatrix[0].size()-1;
		    int iSize = vctMatrix.size();
		    
		    for(int iStart = 0;iStart < iSize; ++iStart)
		    {
		    	// Only try to Search the element if it is possible its present in the list
		        if(vctMatrix[iStart][0] <= iTarget && iTarget <= vctMatrix[iStart][iEnd])
		        {
		            bFlag = BinarySearch(vctMatrix[iStart], 0, iEnd, iTarget);   
		            break;    
		        }
		    }
		    return bFlag;
		}
    
		bool BinarySearch(vector<int>vctRow, int iLow, int iHigh, int iTarget)
		{
		    int iMid;
		    if(iHigh >= iLow)
		    {
		        if(vctRow[iLow] == iTarget)
		        {
		            return true;
		        }
		        else
		        {
		            iMid = iLow + (iHigh - iLow) / 2;
		            if(vctRow[iMid] == iTarget)
		                return true;
		            else if(iTarget < vctRow[iMid])
		                return BinarySearch(vctRow, iLow, iMid-1, iTarget);
		            else
		                return BinarySearch(vctRow, iMid+1, iHigh, iTarget);
		        }
		    }
		    return false;
		}
};

int main()
{
	vector<vector<int>> vctInput =
	{
		{1,3,5,6},
		{10,11,16,20},
		{23,30,34,60}
	};

	vector<int> vctTargets =
	{
		3,			// True
		12,			// False
		34,			// True
		0, 			// False
	};

	Solution objSolution;
	bool bOutput;
	cout << "\nInput: matrix = ";
	for(auto vct : vctInput)
	{
		cout<<"[ ";
		for(auto i : vct)
		{
			cout << i << ",";
		}
		cout<<"\b]"<<endl;
		cout<<"\t\t";
	}
	
	for(auto test : vctTargets)
	{
		bOutput = objSolution.searchMatrix(vctInput, test);
		cout<<"\nOutput for Target: "<<test<<": "<<bOutput<<endl;
	}		
}

/*
	Input: matrix = [ 1,3,5,6]
                [ 10,11,16,20]
                [ 23,30,34,60]

	Output for Target: 3: 1

	Output for Target: 12: 0

	Output for Target: 34: 1

	Output for Target: 0: 0

*/
