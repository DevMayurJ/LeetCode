#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
        
        bool isVowel(char ch)
        {
            return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
        }
    
        string reverseVowels(string strInp) 
        {
            int iStart = 0;
            int iEnd = strInp.size() - 1;
            
            // Basic string reverse logic with some change for reversing just vowels
            while(iStart < iEnd)
            {
                bool bCond1 = isVowel(strInp[iStart]);
                bool bCond2 = isVowel(strInp[iEnd]);
                // Both characters are vowels so just swap
                if(bCond1 && bCond2)
                {
                    char strTemp = strInp[iStart];
                    strInp[iStart] = strInp[iEnd];
                    strInp[iEnd] = strTemp;
                    // Increment and Decrement the start and end pointer resp. after swapping
                    ++iStart;
                    --iEnd;
                }
                else if(bCond1)		// If Only first character is Vowel
                {
                    --iEnd;			// Just decrement the end pointer
                }
                else if(bCond2)		// If Only second character is Vowel
                {
                    ++iStart;		// Just increment the start pointer
                }
                else
                {
                	// Both characters are not vowels
                	// Get to next characters
                    ++iStart;
                    --iEnd;
                }
            }
            
            return strInp;
        }
};

int main()
{
	vector<string> vctInput = {"Hello", "eMINeM", "iU", "AchEyvoU", "exAdhIyo"};
	string strRet = "";
	
	Solution objSolution;
	
	for(auto str : vctInput)
	{
		strRet = objSolution.reverseVowels(str);
		cout<<"Input: \""<<str<<"\""<<endl;
		cout<<"Output: \""<<strRet<<"\""<<endl<<endl;
	}
	
	return 0;
}
/*
	Input: "Hello"
	Output: "Holle"

	Input: "eMINeM"
	Output: "eMINeM"

	Input: "iU"
	Output: "Ui"

	Input: "AchEyvoU"
	Output: "UchoyvEA"

	Input: "exAdhIyo"
	Output: "oxIdhAye"

*/
