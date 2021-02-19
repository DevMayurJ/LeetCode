/*
	Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.
	
	Example: Input = "leetcode"
			 Output: 0.
			 Input = "loveleetcode"
			 Output: 2.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
	public:
			int firstUniqChar(string s) 
			{
				int iStrLen = s.length();
				char chCurrChar;
				vector<char> vctCache;
				vector<char>::iterator it; 
				
				for(int i = 0; i < iStrLen; ++i)
				{
				    chCurrChar = s.at(i);
				    it = find (vctCache.begin(), vctCache.end(), chCurrChar);
				    //Search the character only if its not in cache i.e if we have not seen the character before
				    if(!(it != vctCache.end()))
				    {
				        vctCache.push_back(chCurrChar);
				        if(!SearchDuplicateOfChar(chCurrChar, s, i, iStrLen)) 
				            return i;
				    } 
				}
				return -1;
			}
			
			bool SearchDuplicateOfChar(char ch, string s, int iPrevPos, int iLen)
			{
				bool bFlag = false;
				for(int i = (iPrevPos+1); i < iLen; ++i)
				{
				    if(ch == s.at(i)){
				        bFlag = true;
				        break;
				    }
				}
				return bFlag;
			}
};

int main()
{
	vector<string> vctInputString = {
								"leetcode",		// 0
								"leelcodoe",	// 4
								"helloh",		// 1
								"poinuohp"		// 2
							};
	Solution objSolution;
					
	for(auto str : vctInputString)
	{
		cout<<endl<<"Input: \""<<str<<"\""<<endl;
		cout<<"Output: "<<objSolution.firstUniqChar(str);
	}
	cout<<endl;
	return 0;
}

/*
	Input: "leetcode"
	Output: 0
	
	Input: "leelcodoe"
	Output: 4
	
	Input: "helloh"
	Output: 1
	
	Input: "poinuohp"
	Output: 2	
*/
