#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int dir[8][2] = {{0,1},{0,-1},{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty())
			return;

		vector<vector<int>> newer(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
			{
				int dead = 0, live = 0;
				if (board[i][j] == 1)
				{
					for (int k = 0; k < 8; ++k)
					{
						if (i+dir[k][0] >= 0 && i+dir[k][0] < board.size() &&
							j+dir[k][1] >= 0 && j+dir[k][1] < board[0].size() &&
							board[i+dir[k][0]][j+dir[k][1]] == 1)
							++live;
					}
					if (live < 2 || live > 3)
							newer[i][j] = 0;
					else newer[i][j] = 1;
				}
				else
				{
					for (int k = 0; k < 8; ++k)
					{
						if (i+dir[k][0] >= 0 && i+dir[k][0] < board.size() &&
							j+dir[k][1] >= 0 && j+dir[k][1] < board[0].size() &&
							board[i+dir[k][0]][j+dir[k][1]] == 1)
							++dead;
					}
					if (dead == 3)
						newer[i][j] = 1;
				}
			}
			board = newer;
    }
};