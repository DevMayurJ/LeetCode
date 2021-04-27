/*
	Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the 	colors in the order red, white, and blue.

	We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
              void mergeSort(vector<int>& arr, int l, int r)
	      {
		    if (l < r) 
		    {
		        int m = l + (r - l) / 2;

		        mergeSort(arr, l, m);
		        mergeSort(arr, m + 1, r);

		        merge(arr, l, m, r);
		    }
		}
		
		void merge(vector<int>&  arr, int iStart, int iMid, int end)
	        {
		    int iStart2 = iMid + 1;

		    if (arr[iMid] <= arr[iStart2])
		    {
		        return;
		    }

		    while (iStart <= iMid && iStart2 <= end) 
		    {
		        if (arr[iStart] <= arr[iStart2])
		        {
		            iStart++;
		        }
		        else 
		        {
		            int iValue = arr[iStart2];
		            int i = iStart2;

		            while (i != iStart)
                            {
		                arr[i] = arr[i - 1];
		                i--;
		            }
		            arr[iStart] = iValue;

		            iStart++;
		            iMid++;
		            iStart2++;
		        }
		    }
		}
	public:
		void sortColors(vector<int>& vctNums) 
		{
			// We'll just use merge sort as it is an in-place algorithm
		    mergeSort(vctNums,0,vctNums.size() - 1);
		}
};

void PrintVector(vector<int> vct)
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
									{2,0,2,1,1,0},
									{2,0,1},
									{0},
									{1}
								};
	Solution objSolution;
				
	for(auto vct : vctInput)
	{
		cout<<"Input : ";
		PrintVector(vct);
		
		objSolution.sortColors(vct);
		
		cout<<"Output : ";
		PrintVector(vct);
		cout<<endl;
	}							
	return 0;
}

/*
	Input : [ 2, 0, 2, 1, 1, 0] 
	Output : [ 0, 0, 1, 1, 2, 2] 

	Input : [ 2, 0, 1] 
	Output : [ 0, 1, 2] 

	Input : [ 0] 
	Output : [ 0] 

	Input : [ 1] 
	Output : [ 1]
	*/
