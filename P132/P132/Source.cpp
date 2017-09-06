#include <iostream>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        return generate(0,s) - 1;
    }

	int generate(int curIndex, string s)
	{
		if (curIndex == s.size())
			return 0;

		for (int length = s.size() - curIndex; length > 0; length--)
		{
			if (!judge(s.substr(curIndex, length)))
				continue;

			return generate(curIndex + length, s) + 1;
		}
	}

	bool judge(string s)
	{
		for (int i = 0, j = s.size() - 1; i <= j; ++i, --j)
			if (s[i] != s[j])
				return false;

		return true;
	}
};

int main()
{
	Solution s;
	cout << s.minCut("aab") << endl;
}