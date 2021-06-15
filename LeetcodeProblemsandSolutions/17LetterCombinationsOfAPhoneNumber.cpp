/*
	Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

	A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
	{2,"abc"} {3,"def"}
	{4,"ghi"} {5,"jkl"} {6,"mno"}
	{7,"pqrs"} {8,"tuv"} {9,"wxyz"}
*/
#include<iostream>
#include<vector>
#include <map>

using namespace std;

class Solution 
{
    public:
        vector<string> letterCombinations(string digits)
        {
            map<int,string> mpNumStr={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
            vector<string>vctRes;

            int iSize = digits.size();
            
            if(iSize == 0)
            {
                return vctRes;
            }
            
            vctRes={{""}};
            int iCnt = 0;
            
            while(iCnt < iSize)
            {
                string no=mpNumStr[(int)(digits[iCnt]-'0')];
                vector<string>temp;
                for(int i = 0;i < vctRes.size();i++)
                {
                    for(int j = 0; j < no.size();j++)
                    {
                        temp.push_back(vctRes[i]+no[j]);
                    }
                }
                vctRes=temp;
                iCnt++;
            }
            return vctRes;
        }
};

void printArray(vector<string> vctInp)
{
	cout<<"[ ";
	for(auto x : vctInp)
	{
			cout<<x<<", ";
	}
	cout<<"\b\b]"<<endl;
}

int main()
{
	vector<string> vctInput = {"2", "23", "35", "389"};
	vector<string> vctRet;
	Solution objSolution;
	
	for(auto vct : vctInput)
	{
		vctRet = objSolution.letterCombinations(vct);
		cout<<"Input: \""<<vct<<"\""<<endl;
		cout<<"Output: ";
		printArray(vctRet);
	}
	
	return 0;
}

/*
	Input: "2"
	Output: [ a, b, c] 
	
	Input: "23"
	Output: [ ad, ae, af, bd, be, bf, cd, ce, cf] 
	
	Input: "35"
	Output: [ dj, dk, dl, ej, ek, el, fj, fk, fl] 
	
	Input: "389"
	Output: [ dtw, dtx, dty, dtz, duw, dux, duy, duz, dvw, dvx, dvy, dvz, etw, etx, ety, etz, euw, eux, euy, euz, evw, evx, evy, evz, ftw, ftx, 			fty, ftz, fuw, fux, fuy, fuz, fvw, fvx, fvy, fvz]
*/
