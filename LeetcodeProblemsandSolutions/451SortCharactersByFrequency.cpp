/*
 *	Sort the characters of given string in decreasing order of their frequency
 *	
 *	Example 1: 
 *			Input: "tree"
 *			Output: "eetr"
 *	Example 2:
 *			Input: "aabcccc"
 *			Output: "ccccaab"	
 *			
 */

#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Solution 
{
	public:
			string frequencySort(string s) 
			{
				int i = 0;
				int iStrLen = s.length();
				map<char, int> mpCharFreq;
				multimap<int, char,greater<int>> mmFreqChar;
				string strResult = "";
			   
				for(char c : s)
				{
				    mpCharFreq[c]++;
				    mmFreqChar.insert({mpCharFreq[c], c});
				    ++i;
				}
				for (auto it : mmFreqChar)
				{ 
					// Our multimap has duplicate keys
					// So we only need to select the keys with MAX frequency which we haven't used
				    if(strResult.length() < iStrLen && mpCharFreq[it.second] != 0)
				    {
				        for(i = 0; i < mpCharFreq[it.second]; ++i)
				        {
				            strResult += it.second;
				        }
				        // Make the used character freq 0 so we dont use it again
				        mpCharFreq[it.second] = 0;
				    }
				}	
				return strResult;
			}
};

int main()
{
	vector<string> vctInput = {"tree", "ccaaaabete", "EMINEM", "xyxyyxxqwq", "aabcccc"};
	Solution objSolution;
	
	for(string inp : vctInput)
	{
		cout<<"Input = \""<<inp<<"\""<<endl;
		string strResult = objSolution.frequencySort(inp);
		cout<<"Output = \""<<strResult<<"\""<<endl<<endl;
	}
	
	return 0;
}

/*
	Input = "tree"
	Output = "eetr"

	Input = "ccaaaabete"
	Output = "aaaacceebt"

	Input = "EMINEM"
	Output = "EEMMIN"

	Input = "xyxyyxxqwq"
	Output = "xxxxyyyqqw"

	Input = "aabcccc"
	Output = "ccccaab"
*/
