/*
    Given an array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
    Return the minimum size of the set so that at least half of the integers of the array are removed.

    Input: arr = [3,3,3,3,5,5,5,2,2,7]
    Output: 2
    Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 
    (i.e equal to half of the size of the old array). Possible sets of size 2 are {3,5},{3,2},{5,2}.
    
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution 
{
    public:
        int minSetSize(vector<int>& arr)
        {
            int iSize = arr.size();
            int iSum = 0, i = 0;

            unordered_map<int, int> umNumFreq;
            vector<int> vctFreq;
            
            for(auto n : arr)
            {
                umNumFreq[n]++;
            }
           	
            for(auto it : umNumFreq)
            {
                // Add all frequencies of numbers in the vector
                vctFreq.push_back(it.second);
            }

            // Sort freq vector in descending order
            // Because to calculate the min set size we will start removing elements with maximum frequency
            // until the array size becomes atleast half.
            sort(vctFreq.begin(), vctFreq.end(), greater<int>());

            for(i = 0; i < (iSize / 2); i++)
            {
                iSum += vctFreq[i];
                if(iSum >= (iSize / 2))
                {
                    break;
                }
            }
            
            return i + 1;
        }
};

void printArray(vector<int> arr)
{
    cout<<"[ ";
    for(auto x : arr)
    {
        cout<<x<<", ";
    }

    cout<<"\b\b ]\n";
}

int main()
{
    vector<vector<int>> vctInput = {
                            {9,77,63,22,92,9,14,54,8,38,18,19,38,68,58,19},
                            {3,3,3,3,5,5,5,2,2,7},
                            {7,7,7,7,7,7},
                            {1000,1000,3,7},
                            {1,2,3,4,5,6,7,8,9,10}
                        };
    Solution objSolution;


    for(auto vct : vctInput)
    {
        cout<<"\nInput: ";
        printArray(vct);
        int iRet = objSolution.minSetSize(vct);
        cout<<"Output: "<<iRet<<endl;
    }

    return 0;
}

/*
    Input: [ 9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38, 68, 58, 19 ]
    Output: 5

    Input: [ 3, 3, 3, 3, 5, 5, 5, 2, 2, 7 ]
    Output: 2

    Input: [ 7, 7, 7, 7, 7, 7 ]
    Output: 1

    Input: [ 1000, 1000, 3, 7 ]
    Output: 1

    Input: [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
    Output: 5
*/
