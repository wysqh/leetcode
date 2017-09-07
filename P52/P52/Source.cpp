#include <iostream>
#include <string>
#include <vector>

using namespace std;

//8.08%

class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
		vector<string> chess(n, string(n, '.'));

		solve(sum, chess, 0, n);

		return sum;
    }

	void solve(int& rtValue, vector<string> chess, int index, int n)
	{
		if (index == n)
		{
			rtValue = rtValue + 1;
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
	cout << s.totalNQueens(4) << endl;
	return 0;
}