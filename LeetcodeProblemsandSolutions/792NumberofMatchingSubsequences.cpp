#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;
class Solution 
{
public:

	int numMatchingSubseq(string s, vector<string>& words)
	{
		vector<vector<int>> vctIndex(26);
		//Create an vector that stores indices for each character a-z in S
		for (size_t i = 0; i < s.size(); ++i)
		{
			vctIndex[s[i] - 'a'].push_back(i);
		}

		int iRes = 0;
		for (const auto& word : words)
		{
			int iVal = -1;
			bool bFound = true;

			for (char ch : word)
			{
				// Get an iterator to the first element in the range [first,last) which compares greater than val.
				auto it = upper_bound(vctIndex[ch - 'a'].begin(), vctIndex[ch - 'a'].end(), iVal);
				if (it == vctIndex[ch - 'a'].end())
				{
					bFound = false;
					break;
				}
				else
				{
					iVal = *it;
				}
			}

			if (bFound)
			{
				++iRes;
			}
		}

		return iRes;
	}
};

int main()
{
	vector<vector<string>> vctWords = {
										{ "a","bb","acd","ace"},
										{{"aaaaaa" }},
										{{"kqp" }},
										{{"leeeetcode"}},
										{{""}}
										};

	vector<string> vctInpString = {
					"abcde",
					"bbaaaa",
					"shkgqs",
					"lyyyyyeyyyyyeyyeyeipptpcllllofhjdybue",
					""
	};

	Solution objSolution;
	for (int i = 0; i < vctInpString.size(); ++i)
	{
		cout << "Input: s = \"" << vctInpString[i] << "\"";
		for (auto word : vctWords[i])
		{
			cout << " t = \"" << word.c_str() << "\"";
		}

		cout << "Output: " << objSolution.numMatchingSubseq(vctInpString[i], vctWords[i]) << endl;
	}
}
