#include <iostream>
#include <string>
#include <vector>

using namespace std;

//6.18%

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> rtValue;
		vector<string> chess(n, string(n, '.'));

		solve(rtValue, chess, 0, n);

		return rtValue;
	}

	void solve(vector<vector<string>>& rtValue, vector<string> chess, int index, int n)
	{
		if (index == n)
		{
			rtValue.push_back(chess);
			return;
		}

		for (int i = 0; i < n; i++)
		{
			chess[index][i] = 'Q';
			if (bValid(chess, index, i))
			{
				solve(rtValue, chess, index + 1, n);
				chess[index][i] = '.';
			}
			else chess[index][i] = '.';
		}
	}

	bool bValid(vector<string> chess, int row, int column)
	{
		int n = chess.size();
		for (int i = 0; i < n; i++)
		{
			if (row != i)
			{
				if (chess[row][column] == chess[i][column])
					return false;
			}

			if (column != i)
			{
				if (chess[row][column] == chess[row][i])
					return false;
			}

			if ( i == 0 )
				continue;

			if (column - i >= 0 && row - i >= 0)
			{
				if (chess[row-i][column-i] == chess[row][column])
					return false;
			}

			if (column + i < n && row - i >= 0)
			{
				if (chess[row-i][column+i] == chess[row][column])
					return false;
			}

			if (column + i < n && row + i < n)
			{
				if (chess[row+i][column+i] == chess[row][column])
					return false;
			}

			if (column - i >= 0 && row + i < n)
			{
				if (chess[row+i][column-i] == chess[row][column])
					return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> ss;
	ss = s.solveNQueens(4);

	for(auto vec:ss)
	{
		for (auto e: vec)
			cout << e << endl;

		cout << endl;
	}
	return 0;
}