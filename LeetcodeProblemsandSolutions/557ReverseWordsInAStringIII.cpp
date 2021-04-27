/*
	Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
	
	Example 1:
			Input: s = "Let's take LeetCode contest"
			Output: "s'teL ekat edoCteeL tsetnoc"
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
	void reverseString(string& s, int iStart, int iEnd)
	{
		if (s.empty())
		{
			return;
		}

		while (iStart < iEnd)
		{
			char chTemp = s[iStart];
			s[iStart] = s[iEnd];
			s[iEnd] = chTemp;
			++iStart;
			--iEnd;
		}
	}

public:
		//without using stack
		string reverseWords_MJ(string strInp)
		{
			int iStart = 0;
			int iEnd = strInp.size();
			while (iStart < iEnd)
			{
				int n = iStart;
				while (n < iEnd && strInp[n] != ' ')
				{
					++n;
				}

				reverseString(strInp, iStart, n - 1);
				iStart = n;
				if (n != iEnd)
				{
					strInp[iStart++] = ' ';
				}
			}

			return strInp;

		}

		//with stack
		string reverseWords_SD(string strInp)
		{
		    stack<char> stChar;
		    string strResult = "";
		    
		    strInp.push_back(' ');
		    
		    for(auto ch : strInp)
		    {	
		    	// Push characters into stack until we find a space
		    	// which means we found a word
		        if(ch != ' ')
		        {
		        	stChar.push(ch);
		        }
		        else
		        {
		        	stChar.push(ch);	
		        	// Pop characters from stack and reverse the word
		            while(!stChar.empty())
		            {
		                strResult.push_back(stChar.top());
		                stChar.pop();
		            }
		        }
		    }
		    // Remove the leading space
		    strResult.erase(strResult.begin());
		    
		    return strResult;
		}
};

int main()
{
	vector<string> vctInput = {"Let's take LeetCode contest", "God Ding", "Hello XYZ, hOw are you?"};
	string strRet = "";
	
	Solution objSolution;
	
	for(auto str : vctInput)
	{
		strRet = objSolution.reverseWords_SD(str);
		cout<<"Input: \""<< str.c_str() <<"\""<<endl;
		cout<<"Output(SD): \""<< strRet.c_str() <<"\""<<endl;
		strRet = objSolution.reverseWords_MJ(str);
		cout << "Output(MJ): \"" << strRet.c_str() << "\"" << endl << endl;
	}
	
	return 0;
}

/*
Input: "Let's take LeetCode contest"
Output(SD): "s'teL ekat edoCteeL tsetnoc"
Output(MJ): "s'teL ekat edoCteeL tsetnoc"

Input: "God Ding"
Output(SD): "doG gniD"
Output(MJ): "doG gniD"

Input: "Hello XYZ, hOw are you?"
Output(SD): "olleH ,ZYX wOh era ?uoy"
Output(MJ): "olleH ,ZYX wOh era ?uoy"
*/
