#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
    bool isAnagram(string s, string t) 
    {
    		// Each index in array will represent an alphabet
    		// So initialized with 26 zeroes's
       		int count[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int i = 0;
		
		int iSize = s.length();
		
		if(iSize != t.length())
		{
			return false;
		}
		
		for(i = 0; i < iSize; i++)
		{
			count[s[i] - 'a']++;
			count[t[i] - 'a']--; 
		}
		
		for(i = 0; i < 26; i++)
		{
			if(count[i] != 0)
			{
				break;
			}
		}
		
		if(i == 26)
		{
			return true;
		}
		else
		{
			return false;
		}
    }
};

int main()
{
	vector<vector<string>> vctInput = {
								{"abc", "cba"}, 
								{"hello", "lloeh"},
								{"anagram","anamarg"},
								{"asdf", "qwer"},
								{"asd","asda"}
							};
	bool bRet = false;
	Solution objSolution;
	
	for(auto vct : vctInput)
	{
		bRet = objSolution.isAnagram(vct[0], vct[1]);
		cout<<"Input: \""<<vct[0]<<"\", \""<<vct[1]<<"\""<<endl;
		cout<<"Output: "<<bRet<<endl<<endl;
	}
	
	return 0;
}

/*
	Input: "abc", "cba"
	Output: 1

	Input: "hello", "lloeh"
	Output: 1

	Input: "anagram", "anamarg"
	Output: 1

	Input: "asdf", "qwer"
	Output: 0

	Input: "asd", "asda"
	Output: 0

*/
