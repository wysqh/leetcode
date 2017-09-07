#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int basic = 0, overlap = 0;

		for (const auto&row : grid)
			for (const auto&col : row)
				if (col == 1)	basic++;

		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size() - 1; j++)
				if (grid[i][j] == 1 && grid[i][j+1] == 1)
					overlap++;
		
		for (int i = 0; i < grid.size() - 1; i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j] == 1 && grid[i+1][j] == 1)
					overlap++;

		return basic*4-overlap*2;
    }
};