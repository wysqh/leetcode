#include <iostream>
#include <string>
#include <vector>

using namespace std;

//41.50%

class Solution {
#define MIN(a,b,c) ((a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)))
public:
    int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 && j > 0)
					dp[i][j] = j;
				if (i > 0 && j == 0)
					dp[i][j] = i;
				if (i > 0 && j > 0)
					dp[i][j] = MIN(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (word1.at(i-1) == word2.at(j-1) ? 0 : 1));
			}
		}

		return dp[m][n];
    }
};

int main()
{
	Solution s;
	cout << s.minDistance("sea", "eat") << endl;
	return 0;
}
