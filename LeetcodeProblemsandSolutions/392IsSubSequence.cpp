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
		    bool bFlag = true;
		    int i = 0;
		    int iPos = 0, iPrevCharPos = -1;
		  
		    if(s == "" && t == "")
            		return bFlag;
			
		    while(i < s.length())
		    {
		        iPos = SearchCharInString(s.at(i), t, iPrevCharPos);
		        if(iPos == -1 )
		        {
		            bFlag = false;
		            break;
		        }
		        iPrevCharPos = iPos;
		        ++i;
		    }       
		    return bFlag;
		}
		
		int SearchCharInString(char ch, string t, int iPrev)
		{
		    for(int i = (iPrev+1); i < t.length(); ++i)
		    {
		        if(ch == t.at(i))
		            return i;
		    }
		    return -1;
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
