#include <deque>
#include <vector>
#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;

	Point(int _x, int _y) : x(_x), y(_y) {}
};

//41.96%

class Solution {
public:
    void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		
		vector<Point> edges;
		for (int i = 0; i < board[0].size(); ++i)
		{
			edges.push_back(Point(0, i));
			edges.push_back(Point(board.size() - 1, i));
		}

		for (int i = 1; i < board.size() - 1; ++i)
		{
			edges.push_back(Point(i, 0));
			edges.push_back(Point(i, board[0].size() - 1));
		}

		vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(),false));
		for (auto& e: edges)
		{
			if (board[e.x][e.y] == 'X' || mark[e.x][e.y])
				continue;

			deque<Point> queue;
			queue.push_back(Point(e.x, e.y));
			while (!queue.empty())
			{
				Point tmp = queue.front();
				queue.pop_front();
				mark[tmp.x][tmp.y] = true;
				board[tmp.x][tmp.y] = '*';
				if (tmp.x - 1 >= 0 && board[tmp.x-1][tmp.y] == 'O' && !mark[tmp.x-1][tmp.y])
				{
					mark[tmp.x - 1][tmp.y] = true;
					queue.push_back(Point(tmp.x - 1, tmp.y));
				}
				if (tmp.x + 1 < board.size() && board[tmp.x+1][tmp.y] == 'O' && !mark[tmp.x+1][tmp.y])
				{
					mark[tmp.x + 1][tmp.y] = true;
					queue.push_back(Point(tmp.x + 1, tmp.y));
				}
				if (tmp.y - 1 >= 0 && board[tmp.x][tmp.y-1] == 'O' && !mark[tmp.x][tmp.y-1])
				{
					mark[tmp.x][tmp.y - 1] = true;
					queue.push_back(Point(tmp.x, tmp.y - 1));
				}
				if (tmp.y + 1 < board[0].size() && board[tmp.x][tmp.y+1] == 'O' && !mark[tmp.x][tmp.y+1])
				{
					mark[tmp.x][tmp.y + 1] = true;
					queue.push_back(Point(tmp.x, tmp.y + 1));
				}
			}
		}

		for (int i  = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				switch (board[i][j])
				{
				case 'X': break;
				case 'O': board[i][j] = 'X'; break;
				case '*': board[i][j] = 'O'; break;
				default:	break;
				}

    }
};

int main()
{
	Solution s;
	char a[][21] = {"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO",
		"OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO",
		"OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO",
		"OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO",
		"OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO",
		"OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO",
		"OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"};
	vector<vector<char>> dp(18);
	for (int i = 0; i < 18; ++i)
		dp[i].assign(begin(a[i]), end(a[i]));
	cout << 1 << endl;
	s.solve(dp);
}