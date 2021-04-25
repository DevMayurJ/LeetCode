/*
	Given a sentence text 
	First letter is in upper case.
	Each word in text are separated by a single space.

	Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. 
	If two words have the same length, arrange them in their original order.

	Return the new text following the format shown above
	
	Example 1:
		Input: text = "Leetcode is cool"
		Output: "Is cool leetcode"
		Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
		Output is ordered by length and the new first word starts with capital letter.
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution 
{
    public:
    	string arrangeWords_SD(string text) 
        {
	    // For this we'll use map with vector of strings
	    // As there can be multiple words with same length
	    map<int , vector<string>> mpLenWord;
	    string word="";
	    int iLen = text.length();
        	
            // Convert first letter to lowercase
            // As the first word in result string might be different
            text[0] = tolower(text[0]);
            
            text.push_back(' ');
            
            for(auto ch : text)
            {
            	// Extract a single word
                if(ch == ' ')
                {
                    // Insert in map according to its length
                    // The strings of same length will be appended as we find them
                    // So we don't have to worry about ordering them
                    mpLenWord[word.length()].push_back(' ' + word);
                    // Reset to store next word
                    word="";
                }
                else
                {
            	    word.push_back(ch);
            	}
            }

            text="";

            for(auto itr = mpLenWord.begin(); itr != mpLenWord.end(); itr++)   
            {
            	// Append words starting from length 0 to form a sentence
             	for(int j = 0; j < itr->second.size(); j++) 
               	{
                   text.append(itr->second[j]);
               	}
            }
            
            // Remove the leading space
	    text.erase(text.begin());
	    // Convert First letter to uppercase
            text[0] = toupper(text[0]);
            return text;
        }
}; 


int main()
{
	vector<string> vctInput = {"Leetcode is cool", "Keep calm and code on", "To be or not to be", "XYZM is my name"};
	Solution objSolution;
	
	for(string inp : vctInput)
	{
		cout<<"Input = \""<<inp<<"\""<<endl;
		string strResult = objSolution.arrangeWords_SD(inp);
		cout<<"Output = \""<<strResult<<"\""<<endl<<endl;
	}
	
	return 0;
}
/*
	Input = "Leetcode is cool"
	Output = "Is cool leetcode"

	Input = "Keep calm and code on"
	Output = "On and keep calm code"

	Input = "To be or not to be"
	Output = "To be or to be not"

	Input = "XYZM is my name"
	Output = "Is my xYZM name"

*/
