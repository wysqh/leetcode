#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int min = INT_MAX;
		string result = "";
		if (strs.size() == 0)
			return result;
		else
		{
			for (int i = 0; i < strs.size(); i++)
				if (strs[i].size() < min)
					min = i;

		
			for(int i = 0; i < strs[min].size(); i++)
			{
				bool bSame = true;
				char ch = strs[min].at(i);
				result += ch;

				for (int j = 0; j < strs.size(); j++)
				{
					string cmpStr = strs[j].substr(0, i + 1);
					if (cmpStr != result)
					{
						bSame = false;
						break;
					}
				}

				if (!bSame)
				{
					result = result.substr(0, result.size() - 1);
					break;
				}
			
			}
		}

		return result;
    }
};

int main()
{
	Solution solution;
	vector<string> strs;
	cout << solution.longestCommonPrefix(strs) << endl;
	return 0;
}
