#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		const int rows = matrix.size();
		const int cols = matrix[0].size();
		
		int max_size = 0;
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			{
				if (i == 0 || j == 0)	dp[i][j] = matrix[i][j] - '0';
				else
				{
					if (matrix[i][j] == '0') dp[i][j] = 0;
					else
						dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
				}

				max_size = max(max_size, dp[i][j]);
			}

			return pow(max_size, 2);
    }
};