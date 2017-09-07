#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
	vector<vector<int>> matrix;
	vector<vector<int>> dp;
    NumMatrix(vector<vector<int>> matrix) {
		if (!matrix.empty() && !matrix[0].empty()) 
		{
			this->matrix = matrix;
			dp.resize(matrix.size(), vector<int>(matrix[0].size(), 0));

			for (int i = 0; i < matrix.size(); i++)
				for (int j = 0; j < matrix[0].size(); j++)
				{
					if (i == 0 && j == 0)
						dp[i][j] = matrix[0][0];
					else if (i == 0)
						dp[i][j] = dp[i][j-1] + matrix[i][j];
					else if (j == 0)
						dp[i][j] = dp[i-1][j] + matrix[i][j];
					else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
					+ matrix[i][j];
				}
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		if (matrix.empty() || matrix[0].empty())
			return 0;

		int val = 0;
		if (col1 == 0 && row1 == 0)
			val = dp[row2][col2];
		else if (col1 == 0)
			val = dp[row2][col2] - dp[row1-1][col2];
		else if (row1 == 0)
			val = dp[row2][col2] - dp[row2][col1-1];
		else val = dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1]
			+ dp[row1-1][col1-1];

		return val;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main()
{
	vector<vector<int>> dp;
	vector<int> d;
	dp.push_back(d);
	NumMatrix nu(dp);
	return 0;
}