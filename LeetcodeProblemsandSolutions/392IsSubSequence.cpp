/*

	Given two strings s and t, check if s is a subsequence of t.

	A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without 
	disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

	Example 1:	Input: s = "abc", t = "ahbgdc"
				Output: true

	Example 2:	Input: s = "axc", t = "ahbgdc"
				Output: false
*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
	public:
		bool isSubsequence(string s, string t) 
		{
		   bool bFlag = false;
		   int iTpointer=0, iSpointer=0;
		  
		   if(s.length() == 0)
            		return true;
			
		   while(iTpointer < t.length())
		   {
		        if(s.at(iSpointer) == t.at(iTpointer))
                	{
                     	     iSpointer++;
			     if(iSpointer == s.length())
			     {
				 bFlag=true;
				 break;
			     }
			}
                	++iTpointer;
		  }       
		    return bFlag;
		}
};

int main()
{
	vector<string> vctTest = {
					"abc",
					"aaaaaa",
					"kqp",
					"leeeetcode",
					""
				};
	vector<string> vctInpString = {
					"aghbknc",
					"bbaaaa",
					"shkgqs",
					"lyyyyyeyyyyyeyyeyeipptpcllllofhjdybue",
					""
				};
				
	Solution objSolution;			
	for(int i = 0 ; i < vctTest.size(); ++i)
	{
		cout<<"Input: s = \""<<vctTest[i]<<"\""<<" t = \""<<vctInpString[i]<<"\""<<endl;
		cout<<"Output: "<<objSolution.isSubsequence(vctTest[i], vctInpString[i])<<endl;
	} 
}

/*
	Input: s = "abc" t = "aghbknc"
	Output: 1
	
	Input: s = "aaaaaa" t = "bbaaaa"
	Output: 0
	
	Input: s = "kqp" t = "shkgqs"
	Output: 0
	
	Input: s = "leeeetcode" t = "lyyyyyeyyyyyeyyeyeipptpcllllofhjdybue"
	Output: 1
	
	Input: s = "" t = ""
	Output: 1


*/
