#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board.empty() || board[0].empty())
			return board;
		
		if (board[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'X';
			return board;
		}
        
        if (board[click[0]][click[1]] == 'E')
        {
            int num = rtAdjacentMineNum(board, click);
            if (num == 0)
            {
                board[click[0]][click[1]] = 'B';
                int dir[][2] = {{-1, 0},{-1, -1}, {0, -1}, {1, -1}, {0, 1},
                    {1,1}, {1,0}, {-1, 1}};

                for (int i = 0; i < 8; i++)
                    if (click[0] + dir[i][0] >= 0 && click[0] + dir[i][0] < board.size()
                        && click[1] + dir[i][1] < board[0].size() && click[1] + dir[i][1] >= 0)
                    {
                        click[0] += dir[i][0];
                        click[1] += dir[i][1];    
                        updateBoard(board, click);
                        click[0] -= dir[i][0];
                        click[1] -= dir[i][1];    
                    }
            }
            else board[click[0]][click[1]] = num + '0';
        }
		return board;
    }

	int rtAdjacentMineNum(vector<vector<char>>& b, vector<int>& c)
	{
		int cnt = 0;
		int dir[][2] = {{-1, 0},{-1, -1}, {0, -1}, {1, -1}, {0, 1},
			{1,1}, {1,0}, {-1, 1}};
		
		for (int i = 0; i < 8; i++)
			if (c[0] + dir[i][0] >= 0 && c[0] + dir[i][0] < b.size()
				&& c[1] + dir[i][1] < b[0].size() && c[1] + dir[i][1] >= 0
				&& b[c[0]+dir[i][0]][c[1]+dir[i][1]] == 'M')
				cnt++;

		return cnt;
	}
};