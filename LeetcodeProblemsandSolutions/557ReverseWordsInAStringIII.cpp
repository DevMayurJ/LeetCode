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
	public:
		string reverseWords(string strInp) 
		{
		    stack<char> stChar;
		    string strResult = "";
		    
			// Insert space at end so that we don't skip last word
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
		strRet = objSolution.reverseWords(str);
		cout<<"Input: \""<<str<<"\""<<endl;
		cout<<"Output: \""<<strRet<<"\""<<endl<<endl;
	}
	
	return 0;
}

/*
	Input: "Let's take LeetCode contest"
	Output: "s'teL ekat edoCteeL tsetnoc"

	Input: "God Ding"
	Output: "doG gniD"

	Input: "Hello XYZ, hOw are you?"
	Output: "olleH ,ZYX wOh era ?uoy"
*/
