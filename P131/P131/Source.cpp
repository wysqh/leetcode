#include <string>
#include <vector>
#include <iostream>
using namespace std;

//60.87%

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> rtValue;
		vector<string> container;
		generate(rtValue, container, s, 0);

		return rtValue;
    }

	void generate(vector<vector<string>>& rtValue, vector<string>& container, string s, int curIndex)
	{
		if (curIndex == s.size())
		{
			rtValue.push_back(container);
			return;
		}

		for (int length = 1; curIndex + length <= s.size(); ++length)
		{
			if (!judge(s.substr(curIndex, length)))
				continue;

			container.push_back(s.substr(curIndex, length));
			generate(rtValue, container, s, curIndex + length);
			container.pop_back();
		}
	}

	bool judge(string s)
	{
		if (s.empty())
			return true;

		for (int i = 0, j = s.size() - 1; i <= j; ++i, --j)
			if (s[i] != s[j])
				return false;

		return true;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> d = s.partition("aab");
	for (auto e: d)
	{
		for (auto w:e)
			cout << w << " ";
		cout << endl;
	}

}