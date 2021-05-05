/*
	Given an input string s, reverse the order of the words.
	
	Note that s may contain leading or trailing spaces or multiple spaces between two words. 
	The returned string should only have a single space separating the words. Do not include any extra spaces.
	
	
	Example 1:
		Input: s = "the sky is blue"
		Output: "blue is sky the"

	Example 2:
		Input: s = "  hello world  "	
		Output: "world hello"
		Explanation: Your reversed string should not contain leading or trailing spaces.

	Example 3:
		Input: s = "a good   example"
		Output: "example good a"
		Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
    public:
    	// Using stack
        string reverseWords_SD(string strInp) 
        {
            stack<char> stChar;
            string strResult = "";
            int i = strInp.length() - 1;
            
            // We will Start from end of string because we want to reverse position of the words not the characters in the words
            while(i >= 0)
            {
            	// Push characters into stack until we find a word
                if(strInp[i] != ' ')
                {
                    stChar.push(strInp[i]);
                    --i;
                }
                else
                {
                	// Reverse the words from popping chars from stack
			while(!stChar.empty())
			{
				strResult.push_back(stChar.top());
				stChar.pop();
			}
			// Skip unecessary spaces between words, leading and trailing spaces too
			// Checking i >= 0 first is very important here
			while((i >= 0) && (strInp[i] == ' '))
			{
				--i;
			}
			// Append just one space in between words
			strResult.push_back(' ');
                }
            }
            
            // Empty the stack if there are any words left
            while(!stChar.empty())
            {
                strResult.push_back(stChar.top());
                stChar.pop();
            }
            
            // Remove single leading or trailing space if there are any
            if(strResult[0] == ' ')
            {
            	strResult.erase(strResult.begin());
            }
            
            if(strResult[strResult.length() - 1] == ' ')
            {
            	strResult.erase(strResult.end() - 1);
            }
            
            return strResult;
        }
};

int main()
{
	vector<string> vctInput = {"Leetcode is cool", "a good   example","  Keep   calm   and code on","  hello world  ", "  Hello   qwerty   "};
	
	Solution objSolution;
	
	for(string inp : vctInput)
	{
		cout<<"Input = \""<<inp<<"\""<<endl;
		string strResult = objSolution.reverseWords_SD(inp);
		cout<<"Output = \""<<strResult<<"\""<<endl<<endl;
	}
	
	return 0;
}

/*
	Input = "Leetcode is cool"
	Output = "cool is Leetcode"

	Input = "a good   example"
	Output = "example good a"

	Input = "  Keep   calm   and code on"
	Output = "on code and calm Keep"

	Input = "  hello world  "
	Output = "world hello"

	Input = "  Hello   qwerty   "
	Output = "qwerty Hello"
*/
