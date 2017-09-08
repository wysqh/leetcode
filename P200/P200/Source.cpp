#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
	map<pair<int,int>, bool> visited;
    int numIslands(vector<vector<char>>& grid) {
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				visited[make_pair(i, j)] = false;

		int count = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j] == '1')
					count += (!visited[make_pair(i, j)] ? dfs(grid, i, j), 1 : 0);

		return count;
    }

	void dfs(vector<vector<char>>& grid, int x, int y)
	{
		visited[make_pair(x, y)] = true;
		for (int k = 0; k < 4; k++)
			if (x+dir[k][0] >= 0 && x+dir[k][0] < grid.size() &&
				y + dir[k][1] >= 0 && y + dir[k][1] < grid[1].size() &&
				grid[x+dir[k][0]][y+dir[k][1]] == '1' && 
				!visited[make_pair(x+dir[k][0], y+dir[k][1])])
				dfs(grid, x+dir[k][0], y+dir[k][1]);
					
	}
};