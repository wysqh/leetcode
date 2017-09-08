#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return matrix;

		int row = matrix.size(), col = matrix[0].size();
		res.assign(row, vector<int>(col, -1));
		for (int i = 0; i < row; i++)
			for (int j  = 0; j < col; j++)
				if (matrix[i][j] == 0)
					res[i][j] = 0;

		helper(matrix, 0);
		return res;
    }

	void helper(vector<vector<int>>& matrix, int distance)
	{
		bool ret = true;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				ret &= (res[i][j] != -1);
		if (ret) 
			return;

		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (res[i][j] != -1)
					continue;

				bool exist = false;
				for (int k = 0; k < 4; ++k)
					if (i+dir[k][0] >= 0 && i+dir[k][0] < matrix.size() &&
						j+dir[k][1] >= 0 && j+dir[k][1] < matrix[0].size() &&
						res[i][j] != distance)
						exist |= (res[i+dir[k][0]][j+dir[k][1]] == distance);

				if (exist)
						res[i][j] = distance + 1;
			}

		helper(matrix, distance+1);
	}
};