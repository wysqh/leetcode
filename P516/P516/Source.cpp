#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		if (s.empty()) return 0;

		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int len = 1; len <= s.size(); len++)
		{
			for (int lhs = 0; lhs + len <= s.size(); lhs++)
			{
				int rhs = lhs + len -1;
				if (lhs == rhs)
					dp[lhs][rhs] = 1;
				else if (lhs+1 == rhs)
					dp[lhs][rhs] = (s[lhs] == s[rhs] ? 2: 1);
				else
				{
					int add = s[lhs] == s[rhs] ? 2 : 0;
					dp[lhs][rhs] = max(max(dp[lhs+1][rhs], dp[lhs][rhs-1]), dp[lhs+1][rhs-1] + add);
				}
			}
		}
		return dp[0].back();
    }
};