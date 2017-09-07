#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
		if (s.empty())
			return 0;

		const int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

		for (int len = 1; len <= size; len++)
			for (int i = 0; i + len <= size; i++)
			{
				int j = i + len - 1;
				if (i == j)	dp[i][j] = 1;
				else if (j - i == 1)
					dp[i][j] = 2 + (isPalindromic(s.substr(i, j-i+1)) ? 1 : 0);
				else
				{
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] +
						(isPalindromic(s.substr(i, j-i+1)) ? 1 : 0);
				}
			}

		return dp[0].back();
    }

	bool isPalindromic(string s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}

		return true;
	}
};

int main()
{

}