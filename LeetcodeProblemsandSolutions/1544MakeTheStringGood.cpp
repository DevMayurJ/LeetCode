/*
	Given a string s of lower and upper case English letters.
	
	A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
		s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
	
	Input: s = "leEeetcode"
	Output: "leetcode"
	Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
*/

#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>

using namespace std;

class Solution
{
	public:
		string makeGood_SD(string s)
		{
			if(s != "")
			{
				int iLength = s.size();
				int i = 0;
			
				while(i <= iLength - 2)
				{
					if((islower(s[i]) && isupper(s[i+1]) && s[i] == tolower(s[i+1])) || (isupper(s[i]) && islower(s[i+1]) && s[i] == toupper(s[i+1])))
					{
						// Erase twice with i Because after first erase (i + 1) will become i
						s.erase(s.begin() + i);
						s.erase(s.begin() + i);
						// Decrease string length by 2 after erasing
						iLength -= 2;
						// Reset counter to check for bad characters again after erasing
						i = 0;
					}
					else
					{
						++i;
					}
				}
			}
			return s;
		}
};

int main()
{
	vector<string> vctInput = {"tRee", "ccaAaAbetE", "eMmENeM", "xyZYvbBbVwWYh", "", "leEeetcode"};
	Solution objSolution;
	
	for(string inp : vctInput)
	{
		cout<<"Input = \""<<inp<<"\""<<endl;
		string strResult = objSolution.makeGood_SD(inp);
		cout<<"Output = \""<<strResult<<"\""<<endl<<endl;
	}
	
	return 0;
}
