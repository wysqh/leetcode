#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//0.91%

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
		bool flag = false;
		solve(board, 0, flag);
    }

	void solve(vector<vector<char>>& board, int index, bool& flag)
	{
		if (index >= 81)
		{
			flag = true;
			return;
		}

		if (board[index/9][index%9] != '.')
			solve(board, index+1, flag);
		else
		{
			for (int i = 0; i < 9; i++)
			{
				if (!bValid(board, '1'+i, index/9, index%9))
					continue;

				board[index/9][index%9] = '1'+i;
				solve(board, index+1, flag);
				if (flag)
					break;
				board[index/9][index%9] = '.';
			}
		}
		
	}

	bool bValid(vector<vector<char>> board, char c, int row, int column)
	{
		unordered_map<char, bool> rows;
		unordered_map<char, bool> columns;
		unordered_map<char, bool> subgrid;

		board[row][column] = c;
		for (int i = 0; i < 9; i ++)
		{
			if (board[row][i] != '.')
			{
				if (rows[board[row][i]] == true)
					return false;
				rows[board[row][i]] = true;
			}

			if (board[i][column] != '.')
			{
				if (columns[board[i][column]] == true)
					return false;
				columns[board[i][column]] = true;
			}

			if (board[row/3*3+i/3][column/3*3+i%3] != '.')
			{
				if (subgrid[board[row/3*3+i/3][column/3*3+i%3]] == true)
					return false;
				subgrid[board[row/3*3+i/3][column/3*3+i%3]] = true;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}
